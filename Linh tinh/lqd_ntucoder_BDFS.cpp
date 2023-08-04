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
int n, m, u, v, tplt = 0;
vi a[maxn];
bool vis[maxn];
void DFS(int k) {
	vis[k] = true;
	while(a[k].size()) {
		if(!vis[a[k].back()]) {
			DFS(a[k].back());
		}
		a[k].pop_back();
	}
}
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			DFS(i);
			tplt++;
		}
	}
	cout << tplt;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}