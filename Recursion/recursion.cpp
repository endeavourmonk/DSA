#include<iostream>
using namespace std;

void rec(int n){
    if(n == 0)  return; //Base Case
    cout << n << endl;
    rec(n - 1);
}

int main(){
    int n;
    cin >> n;
    rec(n);
    return 0;    
}