/*
Author: Endeavour Monk
Date: 26.06.2022
*/

#include<iostream>
using namespace std;

int number_of_subsequences_with_sum_K(int *arr, int n, int target, int sum, int ind){
    if(ind == n){
        if(sum == target)   return 1;
        return 0;
    }
    sum += arr[ind];
    int l = number_of_subsequences_with_sum_K(arr, n, target, sum ,ind + 1);

    sum -= arr[ind];
    int r = number_of_subsequences_with_sum_K(arr, n, target, sum ,ind + 1);
    
    return l + r;
}

int main(){
    int n, K;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << "Enter target : ";
    cin >> K;
    int no = number_of_subsequences_with_sum_K(arr, n, K, 0, 0);
    cout << "Number of subsequences with sum " << K << " is " << no;
}