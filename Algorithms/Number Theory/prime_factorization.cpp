// Prime factorization using The sieve of Eratosthenes
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e7+10;

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

void prime_factorization(int n, vector<int> &pf){
    while(n > 1) {
        auto prime_factor = lowest_pf[n];
        while(n % prime_factor == 0){
            n /= prime_factor;
            pf.push_back(prime_factor);
        }
    }
}

int main(){
    sieve_generate();
   
    int n = 70;
    vector<int> pf;
    prime_factorization(n, pf);
    for(auto it : pf)   cout << it << " ";
    return 0;
}