#include<iostream>
using namespace std;

bool isPalindrome(string &str, int i){
    int size_str = str.size();
    if(i >= size_str) return true;
    if(str[i] != str[size_str - 1 - i])    return false;
    return isPalindrome(str, i+1);
}

int main(){
    string str;
    cin >> str;
    bool flag = isPalindrome(str, 0);
    if(flag)    cout << "YES";
    else    cout << "NO";
    return 0;
}