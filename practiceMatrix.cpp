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


int const maxn = 1e6;
int n, m, u, v;
vector<int> a[500];
bool vis[maxn];
void DFS(int u) {
	for(int j = 0; j < a[u].size(); j++) {
		if(!vis[a[u][j]]) {
			vis[a[u][j]] = true;
			DFS(a[u][j]);
		}
	}
}
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	memset(vis, false, sizeof(vis));
	DFS(1);
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}