// Problem:    between-two-sets
// Link:   https://www.hackerrank.com/challenges/between-two-sets/

// Approach:   check all divisors for array b and check if those divisors are multiples of all elements of array a or not if both condition satisfy then we can count them.

//  number should be divisor of all elements of b and multiple of all elements of a.

// TC: O(min(b) * (n + m))

int getTotalX(vector<int> a, vector<int> b)
{
    sort(b.begin(), b.end());
    int ct = 0;
    for (int d = 1; d <= b[0]; ++d) // divisor from 1 to min of b[].
    {
        bool is_fac_b = true;
        for (auto itb : b)
            if (itb % d != 0)
            {
                is_fac_b = false;
                break;
            }

        if (is_fac_b)
        {
            // is d multiple of all the elements of array a.
            bool is_d_mul_a = true;
            for (auto ita : a)
                if (d % ita != 0)
                {
                    is_d_mul_a = false;
                    break;
                }
            if (is_d_mul_a)
                ct++;
        }
    }
    return ct;
}