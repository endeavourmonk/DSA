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

const int N = 1e4;
vector<int> p;
void sieve(){
	vector<bool> pr(N + 1, true);
	pr[0] = pr[1] = false;
	for(int i = 2; i*i <= N; ++i){
		if(pr[i])
			for(int j = i * i; j <= N; j += i)
				pr[j] = false;
	}
	for(int i = 2; i <= N; ++i)
		if(pr[i])
			p.push_back(i);
}

vector<bool> bin;
void intoBin(){
	for (auto i = p.rbegin(); i != p.rend(); ++i){ 
		int n = *i;
		while(n){
			if(n & 1)	{
				bin.insert(bin.begin(), 1);
			}
			else{ 
				bin.insert(bin.begin(), 0);
			}
			n >>= 1;
		}
	} 
	watch(bin.size());
}

void solve(){
	for(auto it: bin)	cout << it << " ";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false);
	cin.tie(0);

	sieve();
	intoBin();
	int tt = 1;
	// cin >> tt;
	while(tt--){
		solve();
	}
	cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}