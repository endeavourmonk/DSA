// Aggressive cows
// https://www.spoj.com/problems/AGGRCOW/

// Approach: We identified the search space for the distance between two cows
// which can be minimum 0 and maximum (maxele - minele), and this is sorted.
// Then start applying binary search on this space and for ss[mid] look for this
// can be distance between cows or not by finding the diff between positions of
// stalls. If ss[mid] is a possible distance then we can look for the right side
// of the ss[mid], the larger side because if two cows can be placed at a distance
// of x then they can also be placed at distance of (x + 1).


bool computeDistance(vector<int> stalls, int cows, int dis) {
    int cowsCount = 1;
    int stPosition = stalls[0];
    for(auto it : stalls){
        if(it - stPosition >= dis){
            cowsCount++;
            stPosition = it;
            if(cowsCount >= cows)
                return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows) {
    int ans = 0;
    int st = 0;
    int end = *max_element(stalls.begin(), stalls.end());
    sort(stalls.begin(), stalls.end());
    while(st <= end){
        int mid = st + (end - st) / 2;
        bool flag = computeDistance(stalls, cows, mid);
        if(flag) {
            st = mid + 1;
            ans = mid;
        }else{
            end = mid - 1;
        }
    }
    return ans;    
}
