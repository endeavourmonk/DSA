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


const int N = 1e6+10;

vector<bool> sieve(N, 1);
vector<int> lowest_pf(N, 0);
vector<int> highest_pf(N, 0);

void sieve_generate(){
    sieve[0] = sieve[1] = false;
    for (int i = 2; i < N; i++){
        if(sieve[i] == true){
        lowest_pf[i] = highest_pf[i] = i;
            for(int j = 2 * i; j < N; j += i){
                sieve[j] = false;
                highest_pf[j] = i;
                if(lowest_pf[j] == 0)
                    lowest_pf[j] = i;
            }
        }
    }
}

void prime_factorization(int a, int b, int n){
	for(int i = )
    while(n > 1) {
        auto prime_factor = lowest_pf[n];
        while(n % prime_factor == 0){
            n /= prime_factor;
            pf.push_back(prime_factor);
        }
    } 
}

void solve(){
	
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