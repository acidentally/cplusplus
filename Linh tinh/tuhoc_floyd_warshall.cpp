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



int const maxn = 510, INF = (int)1e10 + 10;
int a[maxn][maxn] = {};
int trace[maxn][maxn];
int n, m, u, v, q, j, temp;

void get(int u, int v, queue<int> &q) {
	if(trace[u][v] == 0) q.push(u);
	else {
		get(u, trace[u][v], q);
		get(trace[u][v], v, q);
	}
}

void FloydWarshall() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(a[i][k] == INF || a[k][j] == INF) continue;
				int temp = a[i][k] + a[k][j];
				if(a[i][j] > temp) {
					a[i][j] = a[j][i] = temp;
					trace[i][j] = k;
					trace[j][i] = k;
				}
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	if(n == 1) {
		cout << 0;
		return;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = INF;
			// trace[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		a[i][i] = 0;
	}
	while(m--) {
		cin >> u >> v >> j;
		// cout << u << ' ' << v << ' ' << j << endl;
		a[u][v] = j;
		a[v][u] = j;
	}
	FloydWarshall();
	cin >> q;
	while(q--) {
		cin >> u >> v;
		if(a[u][v] >= INF) cout << -1 << endl;
		else {
			cout << a[u][v] << endl;
			queue<int> q;
			get(u, v, q);
			while(!q.empty()) {
				cout << q.front() << ' ';
				q.pop();
			}
			cout << v << endl;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}