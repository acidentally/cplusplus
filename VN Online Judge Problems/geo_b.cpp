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
#define _USE_MATH_DEFINES
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
double phi(double x, dub y) {
    double ans = atan(y / x);
    if (ans < 0) ans += M_PI;
    if (y < 0) ans += M_PI;
    return ans;
}
double x, y;
void solve() {
    cin >> x >> y;
    double ans1 = phi(x, y);
    cin >> x >> y;
    double ans2 = phi(x, y);
    ans1 -= ans2;
    while(ans1 < 0) ans1 += M_PI;
    while(ans1 > M_PI) ans1 -= M_PI;
    coutdub(10) << ans1;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}