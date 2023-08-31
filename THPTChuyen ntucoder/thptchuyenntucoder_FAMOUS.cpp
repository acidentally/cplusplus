/*
Good luck for those who are trying your best
May the most glorious victory come
File name: thptchuyenntucoder_FAMOUS.cpp
Code by : acident / lckintrovert
Created since : 28/08/2023 ~~ 16:02:56
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
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
int n, q;
int l, r, x;
int a[maxn] = {}, sum[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    cin >> q;
    while(q--) {
        cin >> l >> r >> x;
        // cout << a[r] - a[x - 1] << ' ';
        // cerr << - (r - x + 1) * a[x] << ' ';
        cout << (sum[r] - sum[x - 1]) - (r - x + 1) * a[x] + (x - l + 1) * a[x] - (sum[x] - sum[l - 1]) << endl;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/