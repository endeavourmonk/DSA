// author : bug_29
#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(vector<int> &subseq, int arr[], int n, int ind){
    if(ind == n){
        if(subseq.size() == 0){
            cout << "[ ]";
            return;
        }
        for(auto it : subseq){
        	cout << it << " ";
        }
        cout << endl;
        return;
    }
    // take of pick the parameter index in the subsequence.
    subseq.push_back(arr[ind]);
    printSubsequences(subseq, arr, n, ind+1);
    // not pick or not take condition, this element is not added to subsequence.
    subseq.pop_back();
    printSubsequences(subseq, arr, n, ind+1);
}

int main(){
	vector<int> sub;
    int n;
    cin >> n;
    // int arr[n];
    int *arr = new int(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    printSubsequences(sub, arr, n, 0);
    return 0;
}