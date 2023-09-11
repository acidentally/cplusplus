/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1868A.cpp
Code by : acident / lckintrovert
Created since : 10/09/2023 ~~ 21:05:16
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
int const maxn      =       1e3 + 10;
int const INF       =       1e18;
 
int n, x;
void solve() {
    
    cin >> n;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        cur ^= x;
    }
    if(cur == 0) {
        cout << 1 << endl;
        cout << 1 << ' ' << n << endl;
        return;
    }
    if(n % 2 == 0) {
        cout << 2 << endl;
        cout << 1 << ' ' << n << endl << 1 << ' ' << n << endl;
        return;
    }
    cout << 4 << endl;
    cout << 1 << ' ' << n << endl;
    cout << 1 << ' ' << n - 1 << endl;
    cout << n - 1 << ' ' << n << endl;
    cout << n - 1 << ' ' << n << endl;

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