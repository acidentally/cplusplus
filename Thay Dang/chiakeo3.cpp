/*
Good luck for those who are trying your best
May the most glorious victory come
File name: chiakeo3.cpp
Code by : acident / lckintrovert
Created since : 21/08/2023 ~~ 16:59:26
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
// #define int                 long long
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
int const maxn      =       1e3 + 10;
int const INF       =       1e18;
 
int n, a[maxn] = {}, sum = 0;
map<int, bool> m;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    m[a[1]] = 1;
    for(int i = 2; i <= n; i++) {
        vi d;
        for(auto s : m) {
            if(s.fi + a[i] > sum/2) break;
            d.pb(s.fi + a[i]);
        }
        for(auto s : d) m[s] = 1;
    }
    map<int, bool>::iterator ptr = m.lower_bound(sum / 2);
    int ans = ptr -> fi * (sum - ptr -> fi);
    ptr--;
    ans = max(ans, ptr -> fi * (sum - ptr -> fi));
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}