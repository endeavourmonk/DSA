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

const int N = 1e8+1;
vector<pair<bool, pair<int, int>>>sieve(N);
vector<int> pr;
void generate_sieve(){
	sieve[0].first = sieve[1].first = true;
	for(int i = 2; i*i <= N; ++i)
		if(sieve[i].first == false)
			for(int j = i*i; j <= N; j += i)
				sieve[j].first = true;

	pr.push_back(-1);
	for(int i = 2; i <= N; ++i)
		if(sieve[i].first == false)	pr.push_back(i);
}

void row_col_gen(){
	for(int row = 1, k = 1; k < pr.size(); row++){
		for(int col = 1; col <= row && col < pr.size(); ++col){
			sieve[pr[k]].second.first = row;
			sieve[pr[k++]].second.second = col;
		}
	}
}

void solve(){
	int n; 
	cin >> n;
	if(sieve[n].second.first != 0)
		cout << sieve[n].second.first << " " << sieve[n].second.second << endl;
	else cout << -1 << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false);
	cin.tie(0);

	generate_sieve();
	row_col_gen();

	int tt = 1;
	cin >> tt;
	while(tt--){
		solve();
	}

	cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}