/*
Good luck for those who are trying your best
May the most glorious victory come
File name: C.cpp
Code by : acident / lckintrovert
Created since : 27/01/2024 ~~ 21:40:09
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
const int maxn      =        2e5 + 10;
const int INF       =        1e18;

int n, ans, ansR = 0;
int a[maxn] = {};
inline void solve() {
    cin >> n;
    ans = 0; ansR = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = __gcd(ans, a[i]);
    }
    for(int i = 1; i <= n; i++) {
        ansR += a[i]/ans - 1;
    }
    cout << ansR;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/