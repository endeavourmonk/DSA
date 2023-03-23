EKO - Eko
https://www.spoj.com/problems/EKO/

TC: O(n log N)
SC: O(1)

Approach: First we identyfied the search space of the heights which 
can be between the 0 and the max height of the trees. And this space
is sorted means monotonic so that we can apply the binary search on
this heights where low = 0 and high = max element.
Now look if the mid is suitable height or not if yes then we need to 
maximize the ans so look in the right side of the mid else look in
the left of the mid. and for every successful height update ans.

#include<bits/stdc++.h>
using namespace std;
 
bool woodsCollected(long long m, long long h, vector<long long> arr) {  
    // TC: O(n)
    long long sum = 0;
    for(auto it : arr)
        sum += max(1LL * 0, it - h);
    if(sum >= m)
        return true;
    return false;
}
 
int main() {
    long long n, m;
    cin >> n >> m;
    vector <long long> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    long long low = 0, hi = *max_element(arr.begin(), arr.end()), ans = 0;
    // TC: O(log maxel)
    while(low <= hi) {
        long long mid = low + (hi - low) / 2;
        bool flag = woodsCollected(m, mid, arr);
        if(flag) {
            ans = mid;
            low = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans;
} 