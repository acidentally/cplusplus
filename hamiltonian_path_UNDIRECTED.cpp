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

int const maxn = 1e3 + 10;
int n, m, u, v, deg[maxn] = {};
unordered_map<int, int> seg[maxn];
deque<int> ans;
bool vis[maxn] = {};
void DFS(int k, int cnt) {
	if(cnt == n && seg[k][1]) {
		cout << "YES" << endl;
		// cout << 1 << ' ';
		// while(!ans.empty()) {
		// 	cout << ans.front() << ' ';
		// 	ans.pop_front();
		// }
		exit(0);
	}
	for(int i = 1; i <= n; i++) {
		if(seg[i][k] && !vis[i]) {
			vis[i] = true;
			ans.push_back(i);
			seg[i][k]--;
			seg[k][i]--;
			DFS(i, cnt + 1);
			seg[i][k]++;
			seg[k][i]++;
			ans.pop_back();
			vis[i] = false;
		}
	}
}
void solve() {
	cin >> n >> m;
	if(n == 1) {
		cout << "YES";
		exit(0);
	}
	while(m--) {
		cin >> u >> v;
		seg[u][v]++;
		seg[v][u]++;
		deg[u]++;
		deg[v]++;
	}
	for(int i = 1; i <= n; i++) {
		if(deg[i] <= 1) {
			cout << "NO";
			exit(0);
		}
	}
	vis[1] = 1;
	DFS(1, 1);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}