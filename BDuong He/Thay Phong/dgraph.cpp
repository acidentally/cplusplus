/*
Good luck for those who are trying your best
May the most glorious victory come
File name: dgraph.cpp
Code by : acident / lckintrovert
Created since : 17/08/2023 ~~ 14:48:25
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
 
int n, m, u, v, idx[maxn] = {};
vi topo, a[maxn] = {};
int out[maxn] = {}, in[maxn] = {};
priority_queue<int, vi, greater<int> > vertex;
void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        a[u].pb(v);
        out[u]++;
        in[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) vertex.push(i);
        sort(all(a[i]));
    }
    while(!vertex.empty()) {
        u = vertex.top();
        vertex.pop();
        topo.pb(u);
        for(auto s : a[u]) {
            in[s]--;
            if(in[s] == 0) vertex.push(s);
        }
    }
    int cnt = 1;
    for(auto s : topo) {
        idx[s] = cnt++;
    }
    for(int i = 1; i <= n; i++) {
        cout << idx[i] << ' ';
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}