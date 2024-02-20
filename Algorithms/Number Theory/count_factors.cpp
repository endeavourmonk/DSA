#include<iostream>
using namespace std;

//TC = O(sqrt(n))
// If we use sqrt(n) instead of i*i TC will be O(sqrt(n) * log(n)).

int count_factors(int n){
	int ct = 0;
	for(int i = 1; i * i <= n; ++i)
		if(n % i == 0){
			ct++;
			if(n / i != i)	
				ct++;
		}
	return ct;
}

int main(){
    int n = 24;
    cout << count_factors(n);
    return 0;
}