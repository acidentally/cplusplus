/*
Good luck for those who are trying your best
May the most glorious victory come
File name: VOI22_4.cpp
Code by : acident / lckintrovert
Created since : 09/09/2023 ~~ 09:47:32
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
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
int n, u, v, w;
vector<pi> a;
map<pi, int> m;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v >> w;
        a.pb(mp(v, ~u));
        m[mp(u, v)] = w;
    }
    int ans = 0;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/