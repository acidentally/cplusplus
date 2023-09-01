/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cuochop.cpp
Code by : acident / lckintrovert
Created since : 01/09/2023 ~~ 15:38:11
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
int const maxn      =       200;
int const INF       =       1e8;
 
int n, m;
int d[maxn][maxn] = {};
void Floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[j][i] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int u, v, w;

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    while(m--) {
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    Floyd();
    pi ans = mp(1, INF);
    for(int i = 1; i <= n; i++) {
        int curAns = 0;
        for(int j = 1; j <= n; j++) {
            curAns = max(curAns, d[i][j]);
        }
        if(curAns < ans.se) {
            ans = mp(i, curAns);
        }
    }
    cout << ans.fi;
    // cout << d[4][3];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/