/*
Good luck for those who are trying your best
May the most glorious victory come
File name: vnoj_contesttraining_tbc.cpp
Code by : acident / lckintrovert
Created since : 20/08/2023 ~~ 20:28:24
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
 
int n, x, k;
int BIT[maxn] = {}, num[maxn] = {};
int ans = 0, sum = 0;
vi a;
int query(int id) {
    int res = 0, i = id;
    while(i > 0) {
        res += BIT[i];
        i -= (i & (-i));
    }
    return res;
}
void upd(int id) {
    int i = id;
    while(i <= n + 1) {
        BIT[i]++;
        i += (i & (-i));
    }
}
void solve() { 
    cin >> n >> k;
    a.pb(0);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        sum += x - k;
        num[i] = sum;
        a.pb(sum);
    }

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    for(int i = 0; i <= n; i++) {
        x = lower_bound(all(a), num[i]) - a.begin() + 1;
        // cerr << x << endl;
        ans += query(x);
        upd(x);
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}