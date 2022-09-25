#include<iostream>
using namespace std;

// 
void sum(int i,int s){
    if(i < 1){
        cout << s;
        return;
    }
    sum(i - 1, s + i);
}

int main(){
    int n; 
    cin >> n;
    sum(n, 0);
    return 0;
}