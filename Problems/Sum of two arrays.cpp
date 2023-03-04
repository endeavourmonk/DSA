// Sum Of Two Arrays
// https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186?leftPanelTab=0


#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
  // Write your code here.
  // Approach: Start traversing both arrays from end and add the digits
  // and store the sum % 10 in resultant vector and store carry which is 
  // sum / 10. if you traversed the smaller array then start traversing 
  // the longer array and store the remaining elements together with 
  // carry in the resultant vector. At last check if still carry remains
  // then store the carry and finally reverse the resultant vector.

  // TC: O(N) 
  // SC: O(N)


  int i, j, s = 0, carry = 0;
  vector<int> sum;
  int sz = min(n, m);
  
  for(i = n - 1, j = m - 1; i >= 0 && j >= 0; --i, --j){
    s = (a[i] + b[j]) + carry;
    carry = s / 10;
    sum.emplace_back((s % 10));
  }
  // second array is longer
  if(i == -1)
    for(int k = j; k >= 0; --k){
      s = (b[k] + carry);
      carry = s / 10;
      sum.emplace_back((s % 10));
    }
  else{
    for(int k = i; k >= 0; --k){
      s = (a[k] + carry);
      carry = s / 10;
      sum.emplace_back((s % 10));
    }
  }
  if (carry)
    sum.emplace_back(carry);
  reverse(sum.begin(), sum.end());
  return sum; 
}