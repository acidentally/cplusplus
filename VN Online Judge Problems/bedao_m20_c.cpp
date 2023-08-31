/*
Good luck for those who are trying your best
May the most glorious victory come
File name: bedao_m20_c.cpp
Code by : acident / lckintrovert
Created since : 31/08/2023 ~~ 12:39:24
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
int const mod       =       1e9 + 7;
int const maxn      =       1e3 + 120;
int const INF       =       1e18;

int n, a[maxn] = {}, dp[1050] = {};
int c, x, temp;

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    while(n--) {
        cin >> x;
        string s = to_string(x);
        sort(all(s));
        temp = s.size();
        s.erase(unique(all(s)), s.end());
        if(temp != s.size()) continue;
        c = 0;
        for(auto &p : s) {
            p -= '0';
            c += (1 << p);
        } 
        for(int i = 1; i < 1024; i++) {
            dp[c] = max(dp[c], x);  
        }
    }
    int ans = 0;
    for(int i = 1; i < 1024; i++) {
        for(int j = 1; j < 1024; j++) {
            if((i & j)== 0) {
                dp[i | j] = max(dp[i | j], dp[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}