/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 2array.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 16:23:47
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
 
int n, m, c;
void solve() {
    cin >> n >> m;
    int a = 1, b = 1;
    while(n--) {
        cin >> c;
        (a *= c) %= mod;
    }
    while(m--) {
        cin >> c;
        (b *= c) %= mod;
    }
    if(a == b) cout << 1 << endl;
    else cout << 0 << endl;
    return;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}