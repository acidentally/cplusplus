/*
Good luck for those who are trying your best
May the most glorious victory come
File name: robot.cpp
Code by : acident / lckintrovert
Created since : 12/08/2023 ~~ 09:17:44
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
int const mod       =       1e6 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, m, x, y;
vi X, Y, preSumX, preSumY;
char c;
int u = 0, v = 0;
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }
    sort(all(X)); sort(all(Y));
    preSumX.pb(X[0]);
    preSumY.pb(Y[0]);
    for(int i = 1; i < n; i++) {
        preSumX.pb(X[i] + preSumX[i - 1]);
        preSumY.pb(Y[i] + preSumY[i - 1]);
    }   
    while(m--) {
        cin >> c;
        switch(c) {
            case 'S': {v++; break;}
            case 'J': {v--; break;}
            case 'I': {u++; break;}
            case 'Z': {u--; break;}
        };
        int iU = upper_bound(all(X), u) - X.begin() - 1;
        int iV = upper_bound(all(Y), v) - Y.begin() - 1;
        int sum = (iU + 1) * u - preSumX[iU] + (iV + 1) * v - preSumY[iV];
        if(iU != n - 1) sum += preSumX[n - 1] - preSumX[iU] - (n - iU - 1) * u;
        if(iV != n - 1) sum += preSumY[n - 1] - preSumY[iV] - (n - iV - 1) * v;
        cout << sum << endl;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("robot.INP", "r", stdin);
    freopen("robot.OUT", "w", stdout);
    solve();
}