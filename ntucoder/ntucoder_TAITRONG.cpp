
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: ntucoder_TAITRONG.cpp
Code by : acident / lckintrovert
Created since : 07/08/2023 ~~ 15:59:11
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
vector<pi> a[maxn] = {};
void solve() {
    cin >> n >> m >> s >> t;
    priority_queue<pi> q;
    for(int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    while(m--) {
        cin >> x >> y >> z;
        a[x].pb(mp(z, y));
        a[y].pb(mp(z, x));
    }
    // q.push(mp(maxn, s));
    for(auto it : a[s]) {
        d[it.se] = it.fi;
    }
    while(!q.empty()) {
        int du = q.top().fi;
        int u = q.top().se;
        q.pop();
        if(du != d[u]) continue;
        for(auto it : a[u]) {
            int v = it.se, dv = it.fi;
            if(dv >= min(du, d[u])) {
                d[v] = du;
                q.push(mp(d[v], v));
            }
        }
    }
    cout << d[t];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}