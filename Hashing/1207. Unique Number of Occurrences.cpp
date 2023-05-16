1207. Unique Number of Occurrences
https://leetcode.com/problems/unique-number-of-occurrences/description/

// TC: O(N) per testcase

    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(auto it : arr)
            mp[it]++;
        
        set<int> freq;
        for(auto [key, val] : mp)
            freq.insert(val);
        
        return ((mp.size() == freq.size())) ? true : false;
    }