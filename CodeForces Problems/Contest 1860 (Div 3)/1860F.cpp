/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1860F.cpp
Code by : acident / lckintrovert
Created since : 24/08/2023 ~~ 22:57:45
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
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
int f, w;
int n, a[maxn] = {};
bool check[maxn] = {};
void solve() {
    cin >> f >> w;
    cin >> n;
    int sum = 0, ans = 1e6;
    memset(check, 0, sizeof(check));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int j = 1; j <= n; j++) {
        for(int i = sum; i >= 1; i--) {
            if(check[i] && i + a[j] <= sum) check[i + a[j]] = 1;
        }
        check[a[j]] = true;
    }
    for(int i = 1; i <= sum; i++) {
        if(!check[i]) continue;
        int d = max((i - 1) / f + 1, (sum - i - 1) / w + 1);
        ans = min(ans, d);
        d = max((i - 1) / w + 1, (sum - i - 1) / f + 1);
        ans = min(ans, d);
        // cerr << i << ' ' << d << endl;
    }
    cout << ans << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}