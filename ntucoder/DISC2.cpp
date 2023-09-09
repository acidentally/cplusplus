/*
Good luck for those who are trying your best
May the most glorious victory come
File name: DISC2.cpp
Code by : acident / lckintrovert
Created since : 06/09/2023 ~~ 08:20:51
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
 
struct node {
    int pre, nxt;
    node() : pre(0), nxt(0) {}
};

int n, q, u;
node nodes[maxn] = {};
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        nodes[i].pre = i + 1;
        nodes[i].nxt = i - 1;
    }
    int bot = n, top = 1;
    while(q--) {
        cin >> u;
        //pop u out of its place
        if(top == u) {cout << bot << ' '; continue;}
        nodes[nodes[u].pre].nxt = nodes[u].nxt;
        nodes[nodes[u].nxt].pre = nodes[u].pre;
        if(nodes[u].pre == n + 1) bot = nodes[u].nxt; 
        cout << bot << ' ';
        nodes[top].nxt = u;
        nodes[u].pre = top;
        nodes[u].nxt = 0;
        top = u;
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