/*
Good luck for those who are trying your best
May the most glorious victory come
File name: TIMHAISOO.cpp
Code by : acident / lckintrovert
Created since : 13/11/2023 ~~ 09:00:10
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
const int maxn      =        1e6 + 10;
const int INF       =        1e18;

int m, n, prod;
int a, b;
bool found = false;
inline void solve() {
    cin >> m >> n;
    prod = m * n;
    for(int i = m; i * i <= prod; i++) {
        if(prod % i == 0) {
            a = i; b = prod/i;
            if(__gcd(a, b) == m && a * b / __gcd(a, b) == n) {
                cout << a << ' ' << b << endl;
                found = true;
            }
        }
    }   
    if(!found) cout << -1;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/