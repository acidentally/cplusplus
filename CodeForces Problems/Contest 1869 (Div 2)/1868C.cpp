/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1868C.cpp
Code by : acident / lckintrovert
Created since : 10/09/2023 ~~ 21:27:28
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
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n, m;
void solve() {
    cin >> n >> m;
    if(m <= n) {
        if(m == 1) cout << 0 << endl;
        else cout << m << endl;
        int d = 1;
        for(int i = 1; i <= n; i++) {
            if(i < m) d--;
            for(int j = 0; j < m; j++) {
                cout << (j + m + d) % m << ' ';
            } cout << endl;
        }
        return;   
    }
    cout << n + 1 << endl;
    int d = -1;
    for(int i = 1; i <= n; i++) {
        d++;
        for(int j = 0; j < m; j++) {
            cout << (d + j) % m << ' ';
        } cout << endl;
    }
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