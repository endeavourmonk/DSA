//  Intersection Of Two Sorted Arrays
//  Topics: Arrays,
//  Link: https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

// Approach 1 :- traversing arr1 and arr2 looking for equal element and storing them in ans and storing
// the index of the element which are included in ans once.

//  TC: O(N*M)

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.
    vector<int> ans;
    set<int> visited;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((arr1[i] == arr2[j]) && (visited.count(j) == 0))
            {
                ans.push_back(arr1[i]);
                visited.insert(j); // storing index of those elements which are included once in answer to avoid repeating.
                break;
            }
        }
    }
    return ans;
}

//  Approach 2:- Using two pointer we start traversing over both the array and look for the elements are 
//  greater, less or same.

//  TC: O(max(n, m))

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            i++;
        }else if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    return ans;
}