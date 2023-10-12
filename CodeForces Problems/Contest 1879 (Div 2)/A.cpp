/*
Good luck for those who are trying your best
May the most glorious victory come
File name: A.cpp
Code by : acident / lckintrovert
Created since : 25/09/2023 ~~ 10:32:14
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

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

int n;
pi a[maxn] = {};
inline void solve() {
    cin >> n;
    int strength = 0, times = 0, cntS = 0, cntT = 0;
    cin >> a[1].fi >> a[1].se;
    bool eh = 1;
    for(int i = 2; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi < a[1].fi) continue;
        else {
            if(a[i].se >= a[1].se) eh = 0;
        }
    }
    if(!eh) cout << -1 << endl;
    else cout << a[1].fi << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int tc; cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/