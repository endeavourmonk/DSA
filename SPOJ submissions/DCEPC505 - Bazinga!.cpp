#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << #x << " = " << x << "\n"
#define M 1000000007
#define ins insert 
#define pb push_back
#define eb emplace_back
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long double ld;
typedef string str;

const int N = 1000000;
vector<int> lp(N+1);
vector<int> pr;

void create_sieve(){
	for (int i=2; i <= N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j = 0; i * pr[j] <= N; ++j) {
	        lp[i * pr[j]] = pr[j];
	        if (pr[j] == lp[i]) {
	            break;
	        }
	    }
	}
}
const int noTerms = 20000001;
vector<int> terms;

void generate_terms(){
	terms.push_back(-1);
	int ct = 0;
	for(int i = 0; i < pr.size() - 1; ++i)
		for(int j = i + 1; j < pr.size() && ct <= noTerms; ++j){
			terms.push_back(pr[i] * pr[j]);
			ct++;
		}
	sort(terms.begin() ,terms.end());
}

void solve(){
	int n; 
	cin >> n;
	cout << terms[n] << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
    time_t start, end;

	ios::sync_with_stdio(false);
	cin.tie(0);
	time(&start);
	double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
	create_sieve();
	generate_terms();
	time(&end);

	int tt = 1;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}