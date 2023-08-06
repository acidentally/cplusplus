/*
Good luck for those who are trying your best
May the most glorious victory come
File name: CF_18856E1.cpp
Code by : acident / lckintrovert
Created since : 06/08/2023 ~~ 10:18:10
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
int const maxn      =       5e3 + 100;
int const INF       =       1e18;
 
int n, ans = 0, u;
int child[maxn] = {};
vi a[maxn] = {};
void dfs(int k, int par) {
    int t = a[k].size();
    ans += (t >> 1) * ((t >> 1) + (t % 2));
    for(auto s : a[k]) {
        if(s == par) continue;
        dfs(s, k);
    }
}
void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        cin >> u;
        a[i].pb(u); 
        a[u].pb(i);
    }
    dfs(1, -1);
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}