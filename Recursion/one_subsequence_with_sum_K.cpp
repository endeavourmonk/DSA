/* author : Endeavour monk
    date : 25.06.2022
*/
#include<iostream>
#include<vector>
using namespace std;

int call_no = 1;
bool printSubsequences(vector<int> &subseq, int arr[], int n, int sum, int target, int ind){
    // cout << "call - " << call_no++ << endl; 

        if(sum == target){
            for(auto it : subseq)   cout << it << " ";
            cout << endl;
            return true;
        }

    if(ind == n)    return false;

    // take the parameter index in the subsequence and add the element at index in sum.
    subseq.push_back(arr[ind]);
    sum += arr[ind];
    if(printSubsequences(subseq, arr, n, sum, target, ind+1) == true) return true;  // 1st call when you pick element

    // not take condition, this element is not added to subsequence and subtract the element from your sum.
    sum -= arr[ind];
    subseq.pop_back();
    if(printSubsequences(subseq, arr, n, sum, target, ind+1) == true) return true;   // 2nd call if you not pick
    return false;
}

int main(){
	vector<int> sub;
    int n, target;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << "Enter target ";
    cin >> target;
    printSubsequences(sub, arr, n, 0, target, 0);
    return 0;
}