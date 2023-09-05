/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Bai2.cpp
Code by : acident / lckintrovert
Created since : 04/09/2023 ~~ 13:45:14
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
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define ins                 insert
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       3e5 + 10;
int const INF       =       1e18;
 
int n, x;
vi a;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a.pb(x);
    }
    int d = n;
    for(int i = n - 1; i >= 0; i--) {
        if(d == a[i]) d--;
    }
    cout << d;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("xs.inp", "r", stdin);
    freopen("xs.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/