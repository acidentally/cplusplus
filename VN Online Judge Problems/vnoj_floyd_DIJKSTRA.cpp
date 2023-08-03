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
int const INF = 100000;

int d[110][110] = {}, trace[110][110] = {};
vector<pi> a;
int n, m, q, u, v, c;
void Dijkstra(int k) {
	priority_queue< pi, vector<pi>, greater<pi> > q;
	q.push({0, k});
	while(!q.empty()) {
		int du = q.top().fi, u = q.top().se;
		q.pop();
		if(du != d[u]) continue;
	}
}
void compute(int a, int b) {
	deque<int> ans;
	while(b != a) {
		ans.push_back(b);
		b = trace[a][b];
	}
	cout << a << ' ';
	while(!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop_front();
	}
}
void solve() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	} 
	while(m--) {
		cin >> u >> v >> c;
		a[u].push_back({c, v});
		a[v].push_back({c, u});
	}
	while(q--) {
		cin >> c >> u >> v;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = INF;
				trace[i][j] = 0;
			}
		}
		Dijkstra(u);
		if(!c) {
			if(u != v) cout << d[u][v] << endl;
			else cout << 0 << endl;
		}
		else {
			if(u == v) cout << 1 << ' ' << u << endl;
			else {
				compute(u, v);
			}
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}