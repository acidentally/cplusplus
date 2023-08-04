/*
Good luck for those who are trying your best
May the most glorious victory come
File name: BDuongHe_chiendich.cpp
Code by : acident / lckintrovert
Created since : 04/08/2023 ~~ 20:44:12
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
int const maxn      =       1e3 + 10;
int const INF       =       1e18;


int n;
double p, l;
pair<dub, dub> a[maxn] = {};
double dp[maxn] = {};
void solve() {
    cin >> n >> p >> l;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi > p) {
            cout << -1;
            return;
        }
        a[i].se = l / a[i].se;
    }
    dp[1] = a[1].se;
    for(int i = 2; i <= n; i++)  {
        double curW = a[i].fi;
        double curTime = a[i].se;
        dp[i] = a[i].se + dp[i - 1];
        for(int j = i - 1; j > 0; j--) {
            curW += a[j].fi;
            if(curW > p) break;
            curTime = max(curTime, a[j].se);
            dp[i] = min(dp[i], curTime + dp[j - 1]);
        }
    }
    cout << fixed << setprecision(2) << dp[n];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("chiendich.INP", "r", stdin);
    freopen("chiendich.OUT", "w", stdout);
    solve();
}