/*
Good luck for those who are trying your best
May the most glorious victory come
File name: share.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 08:18:37
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
int const INF       =       1e18;

pii compute(pii a, int w) {
    int v1 = a.fi, v2 = a.se.fi, v3 = a.se.se;
    int mini = min(v1, min(v2, v3));
    if(mini == v1) a.fi += w;
    else if(mini == v2) a.se.fi += w;
    else a.se.se += w;
    return a;
}
int maxVal(pii a) {
    return max(a.fi, max(a.se.fi, a.se.se));
}
int n, w[50] = {};
pii dp[(int)(1e6 + 1e5 + 10)] = {};
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }   
    int maxN = (1 << n);
    dp[0] = mp(0, mp(0, 0));
    for(int i = 1; i < maxN; i++) {
        dp[i] = mp(2020, mp(2020, 2020));
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                pii sett = dp[i ^ (1 << j)];
                sett = compute(sett, w[j]);
                if(maxVal(dp[i]) >= maxVal(sett)) {
                    dp[i] = sett;
                }
            }
        }
    }
    cout << maxVal(dp[maxN - 1]);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("SHARE.INP", "r", stdin);
    freopen("SHARE.OUT", "w", stdout);
    solve();
}