/*
Good luck for those who are trying your best
May the most glorious victory come
File name: C.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 22:20:23
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

int n, k;
int a[maxn] = {}, l[maxn] = {}, r[maxn] = {};
bool check[maxn] = {};
inline void solve() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        l[i] = k + 1;
        r[i] = 0;
        check[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        check[a[i]] = 1;
    }
    for(int i = 1, cnt = 1; i <= n && cnt <= k; i++) {
        while(cnt <= a[i]) l[cnt++] = i;
    }
    for(int i = n, cnt = 1; i >= 1 && cnt <= k; i--) {
        while(cnt <= a[i]) r[cnt++] = i;
    }
    for(int j = 1; j <= k; j++) {
        if(!check[j]) {cout << 0 << ' '; continue;}
        cout << (max(r[j] - l[j] + 1, 0ll) << 1) << ' ';
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