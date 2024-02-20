#include <iostream>
using namespace std;

// TC = O(sqrt(n))

bool is_prime(int n){
    if(n < 2)   return false;
    int ct = 2;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0)  ct += 2;
        if(ct > 2)  return false;
    }
    return true;
}

int main(){
    int n = 30;
    for(int i = 1; i != n; ++i){
        if(is_prime(i)) cout << i << " : prime" << endl;
        else cout<< i << "____" << endl;
    }
}