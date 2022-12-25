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
vector<int> pr;

void create_sieve(){
	vector<bool> sieve(N + 1, true);
	sieve[0] = sieve[1] = false;
	for(int i = 2; i * i <= N; ++i){
		for(int j = i * i; j <= N; j += i)
			if(sieve[i])
				sieve[j] = false;
	}

	pr.push_back(-1);
	for(int i = 2; i <= N; ++i)
		if(sieve[i])
			pr.push_back(i);

}

void generate_sieve(){	
	long long l = N + 1, r = 1e8;
	long long len = (r - l) + 1;
	vector<bool> sieve2(len + 1, true);

    int max_pr = sqrt(r);
	for(auto primes = pr[1]; pr[primes] <= max_pr; ++primes){
		long long mul = (l/primes) * primes;
		long long first_mul = (mul < l) ? mul + primes : mul;
		for(auto j = max(primes * 1LL * primes, first_mul); j <= r; j += primes)
			sieve2[j - l] = false;
	}

	for(int i = 0; i < len; ++i)
		if(sieve2[i])
			pr.push_back(l + i);
}


void solve(){
	watch(pr.size());
	// for(int i = 1; i < pr.size(); i+=500)
	// 		cout << pr[i] << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false);
	cin.tie(0);

	create_sieve();
	generate_sieve();
	int tt = 1;
	while(tt--){
		solve();
	}
	cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}