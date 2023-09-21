/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Bai1.cpp
Code by : acident / lckintrovert
Created since : 20/09/2023 ~~ 21:57:58
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
const int INF       =        1e10;

int n, k, sum = 0, ans = 1e9;
int a[maxn] = {};
inline void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        minimize(ans, a[i]);
    }
    // if(k == 2) {cout << 6; return;}
    if(k == 1) {cout << sum; return;}
    if(k == n) {cout << ans; return;}   
    int dp[n + 10][k + 10] = {};
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        int mini = a[i];
        for(int j = 1; j <= k; j++) {
            maximize(dp[i][0], dp[i - 1][j]);
            if(i - j >= 0) {
                minimize(mini, a[i - j + 1]);
                maximize(dp[i][j], mini + dp[i - j + 1][0]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++) maximize(ans, dp[n][i]);
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