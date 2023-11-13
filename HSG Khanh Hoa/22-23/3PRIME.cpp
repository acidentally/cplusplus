/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 3PRIME.cpp
Code by : acident / lckintrovert
Created since : 13/11/2023 ~~ 12:09:33
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
const int maxn      =        20;
const int INF       =        1e18;

bool isPrime[1010] = {};
void eratos() {
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i * i <= 1000; i++) {
        if(!isPrime[i]) {
            for(int j = i * i; j <= 1000; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}

int n, a[maxn] = {}, ans = 0;
vi c;
bool vis[20] = {};
void DFS() {
    if(c.size() == n) {
        bool found = false;
        for(int i = 0; i < n - 2; i++) {
            if(isPrime[c[i] + c[i + 1] + c[i + 2]]) {found = true; break;}
        }
        if(!found) ans++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            c.push_back(a[i]);
            DFS();
            vis[i] = false;
            c.pop_back();
        }
    }
}
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    DFS();
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    eratos();
    solve();
}

/*A place to scribble thoughts

*/