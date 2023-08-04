/*
Good luck for those who are trying your best
May the most glorious victory come
File name: BDuongHe_caesar.cpp
Code by : acident / lckintrovert
Created since : 04/08/2023 ~~ 10:40:42
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e8;
int const maxn      =       500;
int const INF       =       1e18;

int n1, n2, k1, k2;  
int dp[maxn][3][maxn] = {};       
void solve() {              
    cin >> n1 >> n2 >> k1 >> k2;
    int total = n1 + n2;
    dp[1][1][1] = dp[1][2][1] = 1;
    for(int i = 2; i <= total; i++) {
        for(int sec = 1; sec <= min(k1, i); sec++) {
            //dp[i][1][sec] += mọi dp[i - sec][2][j] với j bất kỳ từ 1 tới min(k2, i - sec);
            for(int j = 1; j <= min(k2, i - sec); j++) {
                (dp[i][1][sec] += dp[i - sec][2][j]) % mod;
            }
        }
        for(int sec = 1; sec <= min(k2, i); sec++) {
            //Tương tự dp[i][2][sec] += mọi dp[i - sec][1][j] với j bất kỳ từ 1 tới min(k1, i - sec)
            for(int j = 1; j <= min(k1, i - sec); j++) {
                (dp[i][2][sec] += dp[i - sec][1][j]) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= k1; i++) {
        (ans += dp[total][1][i]) % mod;
    }
    for(int i = 1; i <= k2; i++) {
        (ans += dp[total][2][i]) % mod;
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("caesar.INP", "r", stdin);
    // freopen("caesar.OUT", "w", stdout);
    solve();
}