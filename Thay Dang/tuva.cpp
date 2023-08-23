/*
Good luck for those who are trying your best
May the most glorious victory come
File name: tuva.cpp
Code by : acident / lckintrovert
Created since : 21/08/2023 ~~ 17:13:18
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
int const maxn      =       3e5 + 10;
// int const INF       =       1e18;
 
int n, d;
bool x;
vi a;
void solve() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x) a.pb(i);
    }
    int ans = 0;
    for(int i = 1; i < a.size(); i++) {
        ans += (a[i] - a[i - 1] - 1) / d;
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}