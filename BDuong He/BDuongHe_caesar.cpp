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
int const mod       =       (int)1e8;
int const maxn      =       110;

int n1, n2, k1, k2;  
int dp[maxn][maxn][3] = {};     
void solve() {              
    cin >> n1 >> n2 >> k1 >> k2;  
    for(int i = 1; i <= min(k1, n1); i++) dp[n1 - i][n2][1] = 1;
    for(int i = 1; i <= min(k2, n2); i++) dp[n1][n2 - i][2] = 1;

    for(int i = n1; i >= 0; i--) {
        for(int j = n2; j >= 0; j--) {
            for(int sec = 1; sec <= min(i, k1); sec++) {(dp[i - sec][j][1] += dp[i][j][2] % mod) % mod;}
            for(int sec = 1; sec <= min(j, k2); sec++) {(dp[i][j - sec][2] += dp[i][j][1] % mod) % mod;}   
        }
    }
    cout << ((dp[0][0][1] + dp[0][0][2]) % mod + mod) % mod;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("caesar.INP", "r", stdin);
    // freopen("caesar.OUT", "w", stdout);
    solve();
}