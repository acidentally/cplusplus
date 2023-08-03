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
int n, m, u, v;
bool a[maxn][maxn] {};
bool check[maxn][maxn] = {};
bool vis[maxn] = {};
vector< pair<int, int> > couting;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.fi < b.fi;
}
void dfs(int k) {
	vis[k] = true;
	for(int i = 1; i <= n; i++) {
		if(a[k][i] && !vis[i]) {
			dfs(i);
		}
	}
}
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
		couting.push_back({u, v});
	}
	// sort(couting.begin(), couting.end(), cmp);
	memset(vis, 0, sizeof(vis));
	int tplt = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			tplt++;
			dfs(i);
		}
	}
	bool found = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < couting.size(); i++) {
		a[couting[i].fi][couting[i].se] = 0;
		a[couting[i].se][couting[i].fi] = 0;
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		for(int j = 1; j <= n; j++) {
			if(!vis[j]) {
				dfs(j);
				cnt++;
			}
		}
		a[couting[i].fi][couting[i].se] = 1;
		a[couting[i].se][couting[i].fi] = 1;

		if(cnt > tplt) {
			int mini = min(couting[i].fi, couting[i].se);
			int maxi = max(couting[i].fi, couting[i].se);
			found = true;
			cout << mini << ' ' << maxi;
			cout << endl;
		}
	}
	if(!found) cout << -1;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}