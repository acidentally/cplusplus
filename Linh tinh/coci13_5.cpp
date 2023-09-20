/*
Good luck for those who are trying your best
May the most glorious victory come
File name: coci13_5.cpp
Code by : acident / lckintrovert
Created since : 20/09/2023 ~~ 12:27:56
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        1e5 + 10;
const int INF       =        1e18;

int n, a, b, c, ans = 0;
map<pi, int> m;
inline void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if(!a && !b) continue;
        if(a == 0) m[{0, 1}]++;
        else if(b == 0) m[{1, 0}]++;
        else m[{a / __gcd(a, b), b / __gcd(a, b)}]++;
    }
    int sum = 0, sqSum = 0;
    for(auto s : m) {
        (ans += (s.se % mod) * (((sum * sum - sqSum) >> 1) % mod)) %= mod;
        (sqSum += s.se * s.se) %= mod;
        (sum += s.se) %= mod;
    }
    cout << (ans + (mod << 10)) % mod;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/