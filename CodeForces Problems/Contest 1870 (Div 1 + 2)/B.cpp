/*
Good luck for those who are trying your best
May the most glorious victory come
File name: B.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 21:42:09
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
int const INF       =       1e8;

int n, m, x;
int bitCnt[100] = {};
int a[maxn] = {}, b[maxn] = {};
inline void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int temp = 0;
    for(int i = 1; i <= m; i++) {
        cin >> x;
        temp |= x;
    }

    int minAns = 0, maxAns = 0;
    for(int i = 1; i <= n; i++) {
        maxAns ^= (a[i] | temp);
        minAns ^= a[i];
    } 
    if(n & 1) {
        cout << minAns << ' ' << maxAns << endl;
        return;
    }
    cout << maxAns << ' ' << minAns << endl;

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