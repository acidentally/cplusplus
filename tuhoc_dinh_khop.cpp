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

int const maxn = 1e5 + 10;
vi a[maxn];
bool vis[maxn] = {};
int n, m, u, v;
vector<pair<int, int>> edges;
void dfs(int i) {
	vis[i] = true;
	for(int u : a[i]) {
		if(!vis[u]) dfs(u);
	}
}
bool found = false;
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		edges.push_back({u, v});
	}
	int cnt = 0;
	// memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dfs(i);
			cnt++;
		}
	}
	for(int i = 0; i < edges.size(); i++) {
		int dem = 0;
		for(int j = 1; j <= n; j++) {
			if(!vis)
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	if(!found) cout << -1;
}