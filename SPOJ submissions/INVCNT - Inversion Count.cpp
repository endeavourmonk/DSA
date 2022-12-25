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

void solve(){
	int n, x;
	cin >> n;
	vector<ll> v;
	for(ll i = 0; i < n; ++i){
		cin >> x;
		v.push_back(x);
	}
	ll ict = 0;
	for(ll i = 0; i < n - 1; ++i){
		for(ll j = i + 1; j < n; ++j)
			if(v[i] > v[j])	ict++;
	}	
	cout << ict << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while(tt--){
		solve();
	}
	cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}