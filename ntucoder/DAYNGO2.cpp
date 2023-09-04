/*
Good luck for those who are trying your best
May the most glorious victory come
File name: DAYNGO2.cpp
Code by : acident / lckintrovert
Created since : 02/09/2023 ~~ 15:35:55
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
int const INF       =       -1e6 - 10;
 
int n, a[maxn] = {}, q;
int st[4 * maxn] = {};
void build(int id, int l, int r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}


int get(int id, int l, int r, int u, int v) {
    if(r < u || l > v) return -INF;
    if(u <= l && r <= v) return st[id];
    
    int mid = l + r >> 1;
    int get1 = get(id << 1, l, mid, u, v);
    int get2 = get(id << 1 | 1, mid + 1, r, u, v);
    return min(get1, get2);
}
int u, v;
char x;
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a[i] = a[i - 1];
        if(x == '(') a[i]++;
        else a[i]--;
    }    
    build(1, 1, n);
    while(q--) {
        cin >> u >> v;
        if(a[u - 1] != a[v]) {
            NO; 
        }
        else if(get(1, 1, n, u, v) < a[u - 1]) NO;
        else YES;
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