#include <iostream>
#include <vector>
using namespace std;

// TC = O(nlog(log n))

const int N = 1e7;
vector<bool> sieve(N + 1, 1);

void sieve_generate(){
    sieve[0] = sieve[1] = false;
    for(int i = 2; i <= N; i++)
        if(sieve[i])
            for(int j = 2 * i; j <= N; j += i)
                sieve[j] = false;
}

int main(){
    sieve_generate();
    for(int i = 1; i <= 50; i++)
        cout << i << " = " << sieve[i] << endl;
    return 0;
}