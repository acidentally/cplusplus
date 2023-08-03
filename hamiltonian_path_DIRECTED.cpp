/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int const maxn = 1e4 + 10;
int n, m, u, v, x, c[maxn], tmin = (int)1e18;
unordered_map<int, int> path[maxn];
bool vis[maxn];
int ans = 1e18;
void DFS(int k, int cnt, int len, deque<int> cur) {
    cur.push_back(k);
    vis[k] = true;
    cnt++;
    if((n - cnt + 1) * tmin > ans) return;
    if(cnt == n && (path[k][1] || path[1][k]) && c[k] >= 1) {
        while(!cur.empty()) {
            cout << cur.front() << ' ';
            cur.pop_front();
        }
        cout << 1 << ": " << len + path[1][k] + path[k][1] << endl;
        if(ans == -1) ans = len + path[1][k] + path[k][1];
        else ans = min(ans, len + path[1][k] + path[k][1]);
    } else if(cnt == n) {
        return;
    }
    for(int i = 1; i <= n; i++) {
        if((path[k][i] || path[i][k]) && !vis[i]) {
            if(k == 1) c[i]--;
            vis[i] = true;
            if(path[i][k] < path[k][i] && !path[i][k]) {
            	int temp = path[i][k];
            	path[i][k] = 0;
            	DFS(i, cnt, len + temp, cur);
            	path[i][k] = temp;
            }
            else if(path[k][i] < path[i][k] && !path[k][i]) {
            	int temp = path[k][i];
            	path[k][i] = 0;
            	DFS(i, cnt, len + temp, cur);
            	path[k][i] = temp;
            }
            // DFS(i, cnt, len + path[i][k] + path[k][i], cur);
            vis[i] = false;
            if(k == 1) c[i]++;
        }
    }
    return;
}
void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> x;
        path[u][v] = x;
        tmin = min(tmin, x);
        if(u == 1) {
            c[v]++;
        } else if(v == 1) c[u]++;
    }
    memset(vis, 0, sizeof(vis));
    deque<int> couting;
    DFS(1, 0, 0, couting);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    if(ans == (int)1e18) cout << -1;
    else cout << ans;
}