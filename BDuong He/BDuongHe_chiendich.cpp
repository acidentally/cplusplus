/*
Good luck for those who are trying your best
May the most glorious victory come

File name: BDuongHe_chiendich.cpp
Code by : acident / lckintrovert
Created since : 2023-08-04 ~~ 09:30:23
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
int const mod          =    1e9 + 7;
int const maxn         =    1e3 + 10;
int const INF          =    LLONG_MAX;

struct data {
    int w;
    double v, s;
    data() : w(0), v(0), s(0) {}
    data(int w_, int v_, int s_) : w(w_), v(v_), s(s_) {}
};

int n, p;
double s;
int w[maxn] = {};
double v[maxn] = {};
data dp[maxn][maxn] = {};   
void solve() {
    cin >> n >> p >> s;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        if(w[i] > p) {
            cout << -1;
            return;
        }
    }
    //Note : l/v -> t;
    //Note 2 : dp[i][j] lưu tình trạng tốt nhất của state tại xe thứ i, sau khi đổi tốp j lần
    dp[1][0] = data(w[1], v[1], 0);
    for(int i = 2; i <= n; i++) {
        for(int changes = 0; changes < n; changes++) {
        
        }
    }
    double ans = 10000.0;
    for(int i = 1; i < n; i++) {
        ans = min(ans, dp[n][i].t);
    }
    cout << fixed << setprecision(2) << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}