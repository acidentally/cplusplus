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
int const INF = 100000;

int a[110][110] = {}, trace[110][110] = {};
int n, m, q, c, u, v;
void Floyd() {	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(a[i][k] == INF || a[k][j] == INF) continue;
				int temp = a[i][k] + a[k][j];
				if(a[i][j] > temp) {
					a[i][j] = a[j][i] = temp;
					trace[i][j] = trace[j][i] = k;
				}
			}
		}
	}
}
void compute(int x, int y, queue<int>& ans) {
	if(trace[x][y] == 0) {
		ans.push(x);
		return;
	}
	else {
		compute(x, trace[x][y], ans);
		compute(trace[x][y], y, ans);
	}
}
void solve() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = INF;
		}
	}
	while(m--) {
		cin >> u >> v >> c;
		a[u][v] = c;
		a[v][u] = c;
	}
	Floyd();
	while(q--) {
		cin >> c >> u >> v;
		if(c == 0) {
			if(u == v) {
				cout << 0 << endl;
				continue;
			}
			cout << a[u][v];
		}
		else if(c == 1) {
			if(u == v) {
				cout << 1 << ' ' << u << endl;
				continue;
			}
			queue<int> ans;
			compute(u, v, ans);
			ans.push(v);
			cout << ans.size() << ' ';
			while(!ans.empty()) {
				cout << ans.front() << ' ';
				ans.pop();
			}
		}
		cout << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}