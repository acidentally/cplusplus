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
int n, m, u, v;
vector<int> a[maxn];
deque<pair<int, int> > ans;
bool vis[maxn] = {};
void DFS(int k) {
	vis[k] = 1;
	for(int i = 0; i < a[k].size(); i++) {
		if(!vis[a[k][i]]) {
			ans.push_back({k, a[k][i]});
			DFS(a[k][i]);
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
	DFS(1);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	if(ans.size() == 0) {
		cout << -1;
		exit(0);
	}
	while(!ans.empty()) {
		cout << ans.front().fi << ' ' << ans.front().se << endl;
		ans.pop_front();
	}
}