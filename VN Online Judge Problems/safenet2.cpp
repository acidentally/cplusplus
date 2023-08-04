/*
Good luck for those who are trying your best
May the most glorious victory come
File name: safenet2.cpp
Code by : acident / lckintrovert
Created since : 04/08/2023 ~~ 16:44:06
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
 
int n, m, u, v;
bool vis[maxn] = {};
int low[maxn] = {}, ids[maxn] = {}, id = 1;
void dfs(int k) {
    vis[k] = true;
    ids[k] = num[k] = id++;
    for(int i : k) {
        if(!vis[i]) {
            dfs(i);
            low[k] = min(low[k], low[i]);
        }
        else low[k] = min(low[k], ids[i]);
    }
}
void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}