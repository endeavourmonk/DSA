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

const int N = 1e5;
vector<bool> sieve(N + 1, true);

void generate_sieve(){
	sieve[0] = sieve[1] = false;
	for(int i = 2; i * i <= N; ++i){
		for(int j = i * i; j <= N; j += i)
			if(sieve[i])
				sieve[j] = false;
	}
}

void generatePrimesInRange(long long l, long long r){
	vector<int>primes;
	int lim = sqrt(r);
	for(int i = 2; i <= lim; ++i)
		if(sieve[i])
			primes.push_back(i);

	int len = (r - l) + 1;
	vector<bool>seg(len, true);
	for(auto i:primes){
		long long mul = (l/i)*i;
		int fmul = (mul < l) ? mul + i : mul;
		for(int j = max(fmul, i*i); j <= r; j += i)
			seg[j - l] = false;
	}
	if(l == 1)	seg[0] = false;

	for(int i = 0; i < len; ++i)
		if(seg[i])
			cout << (l + i) << endl;
	cout << endl;
}

void solve(){
	int m, n;
	cin >> m >> n;
	generatePrimesInRange(m, n);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false);
	cin.tie(0);

	generate_sieve();
	int tt = 1;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}