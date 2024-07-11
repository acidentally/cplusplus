/*
Good luck for those who are trying your best
May the most glorious victory come
File name: B.cpp
Code by : acident / lckintrovert
Created since : 09/06/2024 ~~ 21:53:02
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

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

string s;
inline void solve() {
    cin >> s;
    unsigned long long x = 0;
    int l = -1;

    for(int i = 0; i < s.size(); i++) {
        x = (x << 1) + (x << 3) + s[i] - '0';
        //x = 10*x + s[i] - '0'
        l = (l + 1) * 10;
    }
    cerr << l << endl;
    x -= l;
    
    while(x) {
        if(x % 10 == 9 || x % 10 == 0) {
            cout << "NO" << endl;
            return;
        }
        x /= 10;
    }
    cout << "YES" << endl;

    string s; unsigned long long x = 0;
    for(int i = 0; i < s.size(); i++) {
        x = 10*x + s[i] - '0';
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