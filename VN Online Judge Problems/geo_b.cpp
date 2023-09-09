/*
Good luck for those who are trying your best
May the most glorious victory come
File name: geo_b.cpp
Code by : acident / lckintrovert
Created since : 20/08/2023 ~~ 22:07:20
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
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
#define _USE_MATH_DEFINES
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
dub phi(dub x, dub y) {
    if(y == 0.0 && x > 0) return 0.0;
    if(y == 0.0 && x < 0) return M_PI;
    if(x == 0.0 && y > 0) return M_PI/2.0;
    if(x == 0.0 && y < 0) return  3.0 * M_PI / 2.0;
    dub ans = atan(y / x);
    if (ans < 0) ans += M_PI;
    if (y < 0) ans += M_PI;
    return ans;
}
dub x, y, ans1, ans2;
void solve() {
    cin >> x >> y;
    ans1 = phi(x, y);
    cin >> x >> y;
    ans2 = phi(x, y);
    ans1 = max(ans1, ans2) - min(ans1, ans2);
    if(ans1 > M_PI) ans1 = 2.0 * M_PI - ans1;
    coutdub(10) << ans1 << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}