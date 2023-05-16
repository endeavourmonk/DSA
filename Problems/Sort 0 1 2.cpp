//  Sort 0 1 2
//  Arrays, Sorting, Three Pointers
//  Link: https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTab=1

//  Approach: point left and mid to 0th index and right to the rightmost(n - 1)th index and run loop till mid is not greater than right (mid <= right).

//  TC: O(N)

void sort012(int *a, int n)
{
    //   Write your code here
    int l = 0, r = n - 1, m = 0;
    while (m <= r)
    {
        switch (a[m])
        {
        case 0:
            swap(a[l++], a[m++]);
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(a[m], a[r--]);
            break;
        }
    }
}
