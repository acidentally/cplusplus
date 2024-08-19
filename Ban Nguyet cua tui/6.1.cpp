/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 6.1.cpp
Code by : acident / lckintrovert
Created since : 18/07/2024 ~~ 22:01:19
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  unsigned long long
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

int sqr(int a) {
    a %= mod;
    return (a * a) % mod;
}

int modPow(int a, int k) {
    if(k == 0) return 1;
    if(k == 1) return a % mod;
    if(k % 2 == 1) return ((a % mod) * (sqr(modPow(a, k / 2)) % mod)) % mod;
    else return sqr(modPow(a, k / 2)) % mod;
}
inline void solve() {
    int a, b;
    cin >> a >> b;
    a %= mod; b %= mod;
    cout << ((modPow(a, b) % mod) + 100 * mod) % mod;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/