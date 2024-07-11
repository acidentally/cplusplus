/*
Good luck for those who are trying your best
May the most glorious victory come
File name: D.cpp
Code by : acident / lckintrovert
Created since : 23/06/2024 ~~ 22:49:57
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
int const maxn      =       50;
int const INF       =       1e18;

int compute(int n, int a[50]) {
    if(n == 1) return a[1];
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) return 0;
        else if(a[i] == 1) continue;
        res += a[i];
    }
    return (res == 0) ? 1 : res;
}

int n, a[50];
string s;
inline void solve() {
    cin >> n >> s;
    int ans = INF;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1, check = 0; j <= n; j++) {
            if(j == i) {
                a[j] = 10*(s[j - 1] - '0') + s[j] - '0';
                check = 1;
            }
            else a[j] = s[j - 1 + check] - '0';
        }
        minimize(ans, compute(n - 1, a));
    }
    cout << ans << endl;
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