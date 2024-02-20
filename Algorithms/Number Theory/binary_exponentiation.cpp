#include<iostream>
using namespace std;
const int M = 1e9+7;

// recursive approach
// TC: O(log b)

int binary_exp(int a, int b){
    if(b == 0)  return 1;
    else if(b == 1) return a;
    int ans = binary_exp(a, b/2);
    return (b & 1) ? (a * ((ans * 1LL * ans) % M)) % M : (ans * 1LL * ans) % M;
}

// iteretive approach
// TC: O(log b)

int binaryExp(int a, int b){
    int ans = 1; 
    while(b){
        if(b & 1)   ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int main(){
    int a = 2, b = 5;
    // int ans = binary_exp(a, b);
    int ans = binaryExp(a, b);
    cout << a << "^" << b << " = " << ans << endl;
}