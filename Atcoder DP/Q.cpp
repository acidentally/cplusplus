/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Q.cpp
Code by : acident / lckintrovert
Created since : 12/09/2023 ~~ 08:26:17
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n;
int h[maxn] = {}, a[maxn] = {};
int B[maxn] = {}, b[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sz = 1;
    for(int i = 1; i <= n; i++) {
        int nth = upper_bound(b + 1, b + sz + 1, h[i]) - b;
        cerr << nth << ' ' << sz << endl;
        b[nth] = h[i];
        B[nth] += a[i];
        maximize(sz, nth);
    }
    int ans = 0;    
    for(int i = 0; i < sz; i++) maximize(ans, B[i]);
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/