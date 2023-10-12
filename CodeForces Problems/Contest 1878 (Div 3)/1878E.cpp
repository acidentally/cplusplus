/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1878E.cpp
Code by : acident / lckintrovert
Created since : 28/09/2023 ~~ 10:09:31
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

int n, q;
int a[maxn] = {}, st[4 * maxn + 10] = {};
void build(int id, int l, int r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = (st[id << 1] & st[id << 1 | 1]);
}
int get(int id, int l, int r, int u, int v) {
    if(r < u || v < l) return ((1ll << 33) - 1);
    if(u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return (get(id << 1, l, mid, u, v) & get(id << 1 | 1, mid + 1, r, u, v));
}
int l, k;
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while(q--) {
        cin >> l >> k;
        int left = l, right = n;
        while(left < right) {
            int mid = (left + right - 1) / 2 + 1;
            int ans = get(1, 1, n, l, mid);
            if(ans >= k) {
                left = mid;
                continue;
            }
            else right = mid - 1;
        }
        int ans = get(1, 1, n, l, left);
        if(ans < k) cout << -1 << ' ';
        else cout << left << ' ';
    } cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    pi ans;
    auto[ans.fi, ans.se] = mp{1, 2};
}

/*A place to scribble thoughts

*/