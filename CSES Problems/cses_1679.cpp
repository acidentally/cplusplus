/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1697.cpp
Code by : acident / lckintrovert
Created since : 21/08/2023 ~~ 15:35:33
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, m, u, v; 
vi a[maxn] = {}, topo;
int in[maxn] = {};
void solve() {
    cin >> n >> m;  
    while(m--) {
        cin >> u >> v;
        a[u].pb(v);
        in[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        topo.pb(u);
        q.pop();
        for(auto s : a[u]) {
            in[s]--;
            if(in[s] == 0) q.push(s);
        }
    }
    if(topo.size() != n) {
        cout << "IMPOSSIBLE";
        return;
    }
    for(auto s : topo) cout << s << ' ';

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}