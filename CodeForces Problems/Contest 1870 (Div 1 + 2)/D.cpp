/*
Good luck for those who are trying your best
May the most glorious victory come
File name: D.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 23:06:12
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

typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

int n, k, x, c[maxn] = {};
int remain, count;
vector<pi> a;
inline void solve() {
    cin >> n;
    pi ans = mp(0, 0);
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        minimize(ans, mp(c[i], ~i));
    }
    cin >> k;
    remain = k % (ans.fi);
    count = k / ans.fi;
    k %= ans.fi;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    for(int i = ans.se + 1; i <= n; i++) {
        pq.push(mp(c[i], i));
    }
    while(k >= qp.top().fi) {
        
    }
    
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/