/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1867D.cpp
Code by : acident / lckintrovert
Created since : 11/09/2023 ~~ 22:31:59
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
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, k, x, tplt;
bool vis[maxn] = {}, preVis[maxn] = {};
vi a[maxn] = {};
stack<int> st;
bool found = 0;
void dfs(int v, int p = -1) {
    if(vis[v] && !preVis[v]) {
        found = 1;
    }
    vis[v] = 1;
    st.push(v);
    for(auto s : a[v]) {
        if(s == p) continue;
        dfs(s, v);
    }
}
void solve() {
    cin >> n >> k;
    found = 0;
    memset(vis, 0, n + 10);
    memset(preVis, 0, n + 10);
    for(int i = 1; i <= n; i++) a[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> x;    
        a[i].pb(x);
    }
    tplt = 0;
    for(int i = 1; i <= n && !found; i++) {
        if(!vis[i]) dfs(i);
        tplt++;
        while(!st.empty()) {
            preVis[st.top()] = 1;
            st.pop();
        }
    }
    if(!found && tplt > 1) NO;
    else YES;
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