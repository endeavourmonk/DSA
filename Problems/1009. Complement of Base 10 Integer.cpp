// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/description/

// Approach:
// 101 = 5
// 010 = 2
// -------
// 111
// 101  (XOR)
// -------
// 010 - ans

// we noticed that sum is always 111....
// then we need to find the sum whose no. of digits should be equal to the no. of digs in N.
// and then XOR will give us result.

int bitwiseComplement(int n)
{
    int x = 1;
    while (n > x)
        x = (x << 1) + 1;
    return x ^ n;
}