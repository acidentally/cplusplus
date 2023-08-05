/*
Good luck for those who are trying your best
May the most glorious victory come
File name: BDuongHe_Distance.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 08:53:04
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
 
int n, m, a, b;
vector<pi> vec;
void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        vec.pb(mp(a, b));
    }
    sort(all(vec));
    int l = 1, r = 1e18;
    while(l < r) {
        int mid = (l + r - 1) / 2 + 1;
        int res = 0, maxi = 0;
        for(auto s : vec) {
            s.fi = max(s.fi, maxi);
            int more = 0;
            if(s.se - s.fi >= 0) {
                more = (s.se - s.fi) / mid + 1;
            } 
            res += more;
            maxi = s.fi + more * mid;
        }
        if(res >= n) {
            l = mid;
        }
        else if(res < n) {
            r = mid - 1;
        }
    }
    cout << l;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}