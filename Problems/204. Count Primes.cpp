204. Count Primes
https://leetcode.com/problems/count-primes/description/

// Approach: Sieve of Eratosthenes
// First generated the sieve of size n + 1;
// Then look from 0 to n - 1 if the current position in sieve is true 
// then count is ans.

    int countPrimes(int n) {
        const int N = n + 1;
        vector<bool> sieve(N, true);

        sieve[0] = sieve[1] = false;
        for(int i = 2; i < N; ++i)
            if(sieve[i])
                for(int j = 2 * i; j < N; j += i)
                    sieve[j] = false;

        int ct = 0; 
        for(int i = 0; i < n; ++i)
            if(sieve[i])
                ct++;
        return ct;
    }