/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1867A.cpp
Code by : acident / lckintrovert
Created since : 11/09/2023 ~~ 21:37:15
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
//#define _USE_MATH_DEFINES // If meth .__.
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       4e4 + 10;
int const INF       =       1e18;
 
int n, x;
int c[maxn] = {};
void solve() {
    cin >> n;
    vector<pi> a;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.pb(mp(x, i));
    }
    sort(all(a), greater<pi>());
    for(int i = 0; i < n; i++) {
        c[a[i].se] = i;
    }
    for(int i = 0; i < n; i++) {
        cout << c[i] + 1 << ' ';
    } cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/