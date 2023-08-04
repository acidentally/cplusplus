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
vi a[maxn];
set<int> couting[2];
int n, m, vis[maxn], u, v;
void DFS(int k, bool x) {
	vis[k] = x;
	couting[!x].insert(k);
	for(int i = 0; i < a[k].size(); i++) {
		if(vis[a[k][i]] == -1) {
			DFS(a[k][i], !x);
		} else if(vis[a[k][i]] == x) {
			cout << -1;
			exit(0);
		}
	}
}
void solve() {
	cin >> n >> m;
	memset(vis, -1, sizeof(vis));
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == -1 && !a[i].size()) {
			cout << -1;
			exit(0);
		}
		if(vis[i] == -1) {
			DFS(i, 1);
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	for(int i = 0; i < 2; i++) {
		for(auto j : couting[i]) {
			cout << j << ' ';
		}
		cout << endl;
	}
}