/*
Good luck for those who are trying your best
May the most glorious victory come
File name: MAMA.cpp
Code by : acident / lckintrovert
Created since : 04/09/2023 ~~ 08:11:28
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
int const mod       =       1e9;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int SZ;
void upd(int a[maxn], int k, int val) {
    while(k <= SZ) {
        a[k] += val;
        k += k & -k;
    }
}
int query(int a[maxn], int k) {
    if(k == 0) return 0;
    int res = 0;
    while(k > 0) {
        res += a[k];
        k -= k & -k;
    }
    return res;
}
int n, u, ans = 0;
int BIT[maxn] = {}, BITval[maxn] = {};
int a[maxn] = {};
vi a_;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a_.pb(a[i]);
    }
    sort(all(a_));
    a_.erase(unique(all(a_)), a_.end());
    SZ = a_.size();
    int ans = 0, place, sum, cnt;
    for(int i = 1; i <= n; i++) {
        place = lower_bound(all(a_), a[i]) - a_.begin() + 1; //Vị thứ của a[i]
        sum = query(BITval, SZ) - query(BITval, place - 1);
        cnt = query(BIT, SZ) - query(BIT, place - 1);
        
        (ans += sum - cnt * a[i]) %= mod;
        upd(BITval, place, a[i]);
        upd(BIT, place, 1);
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