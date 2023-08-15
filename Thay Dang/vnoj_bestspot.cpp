/*
Good luck for those who are trying your best
May the most glorious victory come
File name: vnoj_bestspot.cpp
Code by : acident / lckintrovert
Created since : 11/08/2023 ~~ 13:02:44
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
int const maxn      =       510;
int const INF       =       1e7;
 
int P, n, C, u, v, w, x;
int dis[maxn][maxn] = {};
vi fav;
void floyd() {
    for(int k = 1; k <= P; k++) {
        for(int i = 1; i <= P; i++) {
            for(int j = 1; j <= P; j++) {
                if(dis[i][k] == INF || dis[k][j] == INF) continue;
                int temp = dis[i][k] + dis[k][j];
                if(temp < dis[i][j]) {
                    dis[i][j] = dis[j][i] = temp;
                }
            }
        }
    }
}
void solve() {
    cin >> P >> n >> C;
    for(int i = 1; i <= P; i++) {
        for(int j = 1; j <= P; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> x;
        fav.pb(x);
    }
    while(C--) {
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    floyd();
    int mini = 1e9, ans = 0;
    for(int i = 1; i <= P; i++) {

        int cur = 0;
        for(auto s : fav) {
            cur += dis[i][s];
        }
        if(cur < mini) {
            mini = cur;
            ans = i;
        } else if(cur == mini) ans = min(ans, i);
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}