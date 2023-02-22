// Cooking Ninjas
// https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174

// Approach: Identify the search space. Minimum time can be 0 and
// maximum time will be (1 + 2 + 3 +..+ m) * max(rank). This is sorted
// so apply binary search on it and check if dish can be prepared in
// mid time or not. For this assign all task to chef 0 till sum is less
// than mid. then change the chef and do the same till sum <= mid. At any
// time when chef count crosses size of rank array or mid > rank then
// return false. If you can perform this activity till your total dish count
// is equal to m then return true from your isPossibleInMidTime(). and try to
// minimize the time by avoiding a part of search space.

// Function to check if total dish can be prepared in mid time
bool isPossibleToCook(vector<int> rank, int m, int mid) {
    int chef = 0;   // for indexing rank
    int chefDishCt = 1, TotalDish = 0;
    int sumTime = 0;    // for counting total time of individual chef.
    while (TotalDish < m) {
        if (sumTime + (rank[chef] * chefDishCt) <= mid) {
            sumTime += (rank[chef] * chefDishCt);
            TotalDish++;
            chefDishCt++;   // dish count of individual chef
        } else {
            chef++;
            chefDishCt = 1;
            if (chef > (rank.size() - 1) || (rank[chef] > mid)) {
                return false;
            }
            sumTime = 0;
        }
    }
    return true;
}

int minCookTime(vector<int> &rank, int m) {
    // Write your code here
    int low = 0, ans = 0;
    int hi = (((1 + m) * m) / 2) * (*max_element(rank.begin(), rank.end()));
    sort(rank.begin(), rank.end());
    while (low <= hi) {
        int mid = low + (hi - low) / 2;
        if (isPossibleToCook(rank, m, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
