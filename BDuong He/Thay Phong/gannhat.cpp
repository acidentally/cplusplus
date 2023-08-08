/*
Good luck for those who are trying your best
May the most glorious victory come
File name: gannhat.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 16:55:33
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       5e5 + 10;
int const INF       =       1e18;
 
int n, m, b, r, u, v;
vi a_, a[maxn] = {}, couting;
int ans[maxn] = {};
void solve() {
    cin >> n >> m >> b >> r;
    for(int i = 1; i <= n; i++) {
        ans[i] = maxn;
    }
    while(b--) {
        cin >> u;
        a_.pb(u);
        ans[u] = 0;
    }
    while(r--) {
        cin >> u;
        couting.pb(u);
    }
    while(m--) {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(auto s : a_) {
        queue<pi> q;
        bool vis[n + 10] = {};
        q.push(mp(s, 0));
        while(!q.empty()) {
            int vertex = q.front().fi, dis = q.front().se;
            q.pop();
            for(auto v_ : a[vertex]) {
                if(vis[v_]) continue;
                ans[v_] = min(ans[v_], dis + 1);
                vis[v_] = true;
                q.push(mp(v_, dis + 1));
            }
        }
    }
    for(auto s : couting) cout << ans[s] << ' ';
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}