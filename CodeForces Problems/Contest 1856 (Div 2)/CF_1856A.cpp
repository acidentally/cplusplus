/*
Good luck for those who are trying your best
May the most glorious victory come
File name: CF_1856A.cpp
Code by : acident / lckintrovert
Created since : 06/08/2023 ~~ 10:44:44
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
int const maxn      =       100;
int const INF       =       1e18;
 
int n, a[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int stIdx = -1;
    for(int i = n; i >= 0; i--) {
        if(a[i] < a[i - 1]) {
            stIdx = i - 1;
            break;
        }
    }
    if(stIdx == -1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for(int i = stIdx; i >= 1; i--) {
        ans = max(ans, a[i]);
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