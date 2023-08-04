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

typedef pair<int, int> pi;
int const maxn = 1e5 + 10;
int n, m, u, v;
deque<int> ans;
unordered_map<int, bool> seg[maxn];
vi a[maxn];

void DFS(int k) {
	while(!a[k].empty()) {
		if( seg[k][a[k].back()] ) {
			seg[k][a[k].back()] = seg[a[k].back()][k] = 0;
			int temp = a[k].back();
			a[k].pop_back();
			DFS( temp );
		} 
		else a[k].pop_back();
	}
	ans.push_back(k);
	return;
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		seg[u][v] = 1;
		seg[v][u] = 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(a[i].size() & 1) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
	}
	DFS(1);
	if(ans.size() != m + 1) {
		cout << "IMPOSSIBLE";
		exit(0);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	while(!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop_front();
	}
}