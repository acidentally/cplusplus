/*
Good luck for those who are trying your best
May the most glorious victory come
File name: C.cpp
Code by : acident / lckintrovert
Created since : 24/02/2024 ~~ 22:39:06
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

vi copr[1010];
void init() {
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(__gcd(i, j) == 1) copr[i].pb(j);
        }
    }
}

int n, sum[maxn] = {}, ans;
int smol[1010] = {}, a;
inline void solve() {
    cin >> n;
    ans = -mod;
    sum[n + 1] = mod; sum[0] = 0;
    for(int i = 1; i <= 1005; i++) smol[i] = n + 1;
    for(int i = 1; i <= n; i++) {
        cin >> sum[i];
        a = (int)abs(sum[i]);
        sum[i] += sum[i - 1];
        if(a == 0) continue;
        if(sum[smol[a]] > sum[i - 1]) smol[a] = i - 1;

        for(auto j : copr[a]) {
            if(smol[j] > n) continue;
            maximize(ans, sum[i] - sum[smol[j]]);
        }
    }

    if(ans == -mod) cout << "NOT FOUND\n";
    else cout << ans << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    init();
    int tc; cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/