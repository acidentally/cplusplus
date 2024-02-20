/*
Good luck for those who are trying your best
May the most glorious victory come
File name: D.cpp
Code by : acident / lckintrovert
Created since : 27/01/2024 ~~ 21:42:44
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

vi p;
int n;
bool isPrime[maxn] = {};
void eratos() {
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i * i <= n + 10; i++) {
        if(!isPrime[i]) {
            for(int j = i * i; j <= n + 10; j += i) {
                isPrime[j] = 1;
            }
        }
    }
    for(int i = 2; i <= n + 10; i++) {
        if(!isPrime[i]) p.pb(i);
    }
}

int a[maxn] = {}, b[maxn] = {}, mini = 1e9;
int uniMod = 0;
bool check[maxn] = {};
inline void solve() {

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        if(i >= 2) uniMod = __gcd(uniMod, b[i]);
        minimize(mini, a[i]);
    }
    for(int i = 2; i <= n; i++) {
        b[i] = abs(b[i]);
        for(int j = 0; p[j] < && !check[p[j]]; j++)
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    cin >> n;
    eratos();
    solve();
}

/*A place to scribble thoughts

*/ 