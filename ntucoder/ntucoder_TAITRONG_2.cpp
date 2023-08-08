/*
Good luck for those who are trying your best
May the most glorious victory come
File name: ntucoder_TAITRONG_2.cpp
Code by : acident / lckintrovert
Created since : 07/08/2023 ~~ 16:21:39
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, m, s, t;
int x, y, z;
int d[maxn] = {};
priority_queue<pi, vector<pi>, greater<pi> > a[maxn];
void dfs(int k, int par, int minflow) {
    d[k] = minflow;
    while(!a[k].empty()) {
        int flow = a[k].top().fi, next = a[k].top().se;
        a[k].pop();
        if(next == par) continue;
        if(d[next] > flow) {
            dfs(next, k, flow);
        }
    }
}
void solve() {
    cin >> n >> m >> s >> t;
    while(m--) {
        cin >> x >> y >> z;
        a[x].push(mp(y, z));
        a[y].push(mp(x, y));
    }
    for(int i = 1; i <= n; i++) {
        d[i] = maxn;
    }
    dfs(1, -1, maxn);
    cout << d[t];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}