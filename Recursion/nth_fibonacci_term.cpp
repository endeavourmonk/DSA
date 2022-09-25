#include<iostream>
using namespace std;

int nth_fibonacci_term(int n){
    if(n <= 1)  return n;
    int prev = nth_fibonacci_term(n - 1);
    int sec_prev = nth_fibonacci_term(n - 2);
    return prev + sec_prev;
}

int main(){
    int n;
    cin >> n;
    cout << nth_fibonacci_term(n);
    return 0;
}