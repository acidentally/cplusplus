/*
Good luck for those who are trying your best
May the most glorious victory come
File name: NGHICHTHE.cpp
Code by : acident / lckintrovert
Created since : 04/09/2023 ~~ 10:05:08
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
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define ins                 insert
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, x, a[maxn] = {}, SZ, q;
int BIT[maxn] = {};
int query(int k) {
    int res = 0;
    while(k > 0) {
        res += BIT[k];
        k -= k & -k;
    }
    return res;
}
void upd(int k) {
    while(k <= SZ) {
        BIT[k]++;
        k += k & -k;
    }
}
vi a_;
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a_.pb(x);
    }
    sort(all(a_));
    a_.erase(unique(all(a_)), a_.end());
    int ans = 0;
        for(int i = n; i >= 1; i--) {
            int place = lower_bound(all(a_), a[i]) - a_.begin() + 1;
            ans += query(place);
            upd(place);
        }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/