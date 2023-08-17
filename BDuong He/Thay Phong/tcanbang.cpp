/*
Good luck for those who are trying your best
May the most glorious victory come
File name: tcanbang.cpp
Code by : acident / lckintrovert
Created since : 17/08/2023 ~~ 15:15:03
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n, u, v;
int a[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}