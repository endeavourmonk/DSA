
#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << #x << " = " << x << "\n"
#define M 10000007
#define ins insert 
#define pb push_back
#define eb emplace_back
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long double ld;
typedef string str;

ll binaryExp(ll a, ll b){
    ll ans = 1; 
    if(a == 1)	return ans;
    while(b){
        if(b & 1)   ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

ll solve(ll n, ll k){
	// 2 * (n - 1)^k + 2 * (n-1)^(n - 1) + n^k + n^n
	if(n == 0 && k == 0)	return 0;

	ll ans1 = (2 * (binaryExp(n-1, k) % M + binaryExp(n-1, n-1) % M) % M) % M;
	ll ans2 = (binaryExp(n, k) % M + binaryExp(n, n) % M) % M; 
	ll fin_ans = (ans2 + ans1) % M;
	return fin_ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false);
	cin.tie(0);
	while(true){
		ll n, k;
		cin >> n >> k;
		ll ans = solve(n, k);
		if(ans) // if ans is not 0
			cout << ans << endl;
		else return 0;
	}
	cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}