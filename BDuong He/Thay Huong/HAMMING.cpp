/*
Good luck for those who are trying your best
May the most glorious victory come
File name: HAMMING.cpp
Code by : acident / lckintrovert
Created since : 07/08/2023 ~~ 07:53:39
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
int const maxn      =       2e6 + 10;
int const INF       =       1e18;
 
struct node {
    node* child[2];
    int exist, cnt;
    node() {
        child[0] = child[1] = NULL;
        exist = 0; cnt = 0;
    }
} *root;
 
int n, m, a[maxn] = {};
struct Trie {
    Trie() {
        root = new node();
    }
    void add(int x) {
        node *pos = root;
        for(int j = m; j >= 0; j--) {
            int c = (x >> j) & 1;
            if(pos -> child[c] == NULL) pos -> child[c] = new node();
            pos = pos -> child[c];
            pos -> cnt++;
        }
        pos -> exist++;
    }
    int find(int x, node* start, int depth) {
        if(start -> cnt == 0) return -1;
        if(depth < 0) return 0;
        int c = (x >> depth) & 1;
        int get1 = 0, get2 = 0;
        if(start -> child[c]) get1 = find(x, start -> child[c], depth - 1);
        if(start -> child[1 - c]) get2 = 1 + find(x, start -> child[1 - c], depth - 1);
        return max(get1, get2);
    }
} tri;

void solve() {
    cin >> n >> m;
    root -> cnt = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tri.add(a[i]) ;
    }
    // for(int i = 1; i <= n; i++) {
    //     int ans = 0;
    //     for(int j = 1; j <= n; j++) {
    //         if(j == i) continue;
    //         ans = max(ans, (int)__builtin_popcount(a[i] ^ a[j]));
    //     }
    //     cout << ans << ' ';
    // }
    for(int i = 1; i <= n; i++) {
        cout << tri.find(a[i], root, m) << ' ';
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("HAMMING.INP", "r", stdin);
    // freopen("HAMMING.OUT", "w", stdout);
    solve();
}