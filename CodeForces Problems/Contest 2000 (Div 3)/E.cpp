/*
Good luck for those who are trying your best
May the most glorious victory come
File name: E.cpp
Code by : acident / lckintrovert
Created since : 13/08/2024 ~~ 22:33:58
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

int n, m, k, w, t;
int a[maxn] = {};
inline void solve() {
    priority_queue<int> q1, q2;
    //insert mảng
    cin >> n >> m >> k;
    cin >> w;
    for(int i = 1; i <= w; i++) {
        cin >> t;
        q1.push(t);
    }
    int maxN = min(n - k + 1, k);
    int maxM = min(m - k + 1, k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            w = min(min(n - i + 1, i), maxN) * min(min(m - j + 1, j), maxM);
            q2.push(w);
        }
    }
    //sort mảng
    int ans = 0;
    while(!q1.empty()) {
        int a = q1.top(), b = q2.top();
        q1.pop(); q2.pop();
        ans += a * b;
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