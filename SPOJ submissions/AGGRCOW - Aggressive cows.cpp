#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ins insert
#define pb push_back
#define eb emplace_back
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef string str;
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    int ans = aggressiveCows(v, c);
    cout << ans <<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/CP/input.txt", "r", stdin);
    freopen("E:/CP/output.txt", "w", stdout);
    freopen("E:/CP/error.txt", "w", stderr);
#endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}