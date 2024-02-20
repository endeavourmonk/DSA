#include<iostream>
using namespace std;

// The Euclidean algorithm
// TC - O(log min(a, b))

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int main(){
    int n1 = 55, n2 = 11;
    cout << gcd(n1, n2);
    return 0;
}