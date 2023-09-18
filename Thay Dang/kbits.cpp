/*
Good luck for those who are trying your best
May the most glorious victory come
File name: kbits.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 15:57:12
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

int n, k, cnt = 1;
int SUM[100][100]= {}, CNT[100][100] = {};
map<int, int> m;
inline void solve() {
    cin >> n >> k;
    n--;
    while(n) {
        m[cnt++] = n;
        n >>= 1;
    }
    for(int i = cnt - 1; i >= 1; i--) {
        SUM[i] = ();
        CNT[i] = __buildin_popcount(m[i]);
        for(int c = 2; c <= k; c++) {

        }
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