#include<iostream>
using namespace std;

void reverse_array(int *arr, int n, int i){
    if(i >= n/2)    return;
    swap(arr[i], arr[n - i - 1]);
    reverse_array(arr, n, i+1);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    reverse_array(arr, n, 0);
    for(int i = 0; i < n; i++)  cout << arr[i] << " " ;
}