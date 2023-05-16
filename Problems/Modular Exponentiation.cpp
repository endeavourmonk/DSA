Modular Exponentiation
https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146

// TC: O(log n)
// SC: O(1)

int modularExponentiation(int a, int b, int m) {
	// Write your code here.
	a %= m;
	long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * (a % m)) % m;
        a = ((a % m) * 1LL * (a % m)) % m;
        b >>= 1;
    }
    return res;

}