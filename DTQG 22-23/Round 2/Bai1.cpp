/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Bai1.cpp
Code by : acident / lckintrovert
Created since : 21/09/2023 ~~ 21:50:13
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        2e5 + 10;
const int INF       =        1e18;

int n, k, ans = 0;
int a[maxn] = {}, dp[maxn] = {}, mini[maxn] = {};
deque<int> q;
inline void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1, cur = a[1]; i <= k; i++) {
        dp[i] = 0;
        minimize(cur, a[i]);
        if(i == k) dp[k] = cur;
    }
    for(int i = 1; i <= n; i++) {
        while(!q.empty() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if(q.front() + k <= i) q.pop_front();
        if(i >= k) mini[i] = a[q.front()];
    }
    for(int i = k; i <= n; i++) {
        dp[i] = max(dp[i - 1], mini[i] + dp[i - k]);
        maximize(ans, dp[i]);
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/