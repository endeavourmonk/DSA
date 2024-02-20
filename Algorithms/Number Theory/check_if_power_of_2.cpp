#include<iostream>
using namespace std;

// TC: O(1)
bool is_power_of_2(long long n){
    if((n & (n - 1)) == 0)    return true;
    return false;
}

int main(){
    int tt; 
    cin >> tt; 
    while(tt--){
        long long n;
        cin >> n;
        bool res = is_power_of_2(n);
        if(res)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        
    }
}

