/*
Good luck for those who are trying your best
May the most glorious victory come
File name: number.cpp
Code by : acident / lckintrovert
Created since : 12/08/2023 ~~ 08:17:22
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
 
int n, k;
int a[maxn] = {};
int pre[maxn] = {}, nxt[maxn] = {};
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        pre[i] = i - 1;
        nxt[i] = i + 1;
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    int c = 0;
    for(int r = 2; r <= n && c < k; r++) {
        int l = pre[r];
        while(l > 0 && a[l] < a[r] && c < k) {
            c++;
            a[l] = -1;
            pre[nxt[l]] = pre[l];
            nxt[pre[l]] = nxt[l];
            l = pre[l];
        }
    }
    // cout << c;
    int cnt = 0;
    for(int i = 1; i <= n && cnt < n - k; i++) {
        if(a[i] != -1) {
            // cerr << i << ' ';
            cout << a[i];
            // cnt++;
        }
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    solve();
}