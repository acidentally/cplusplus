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
typedef vector<pi> vp;
int const INF = 1e9 + 10;
int const maxn = 1e4 + 10;
int n, m, p, q, u, v, c;
vector<pi> edge[maxn];

void Dijkstra(int st, int end, vi& a) {
	// int trace[maxn] = {};
	bool vis[maxn] = {};
	int d[maxn] = {};
	for(int i = 1; i <= n; i++) d[i] = INF, vis[i] = 0;
	for(int i = 0; i < a.size(); i++) {
		vis[a[i]] = 1;
	}
	priority_queue<pi, vp, greater<pi> > q;
	d[st] = 0;
	q.push({0, st});
	while(!q.empty()) {
		int du = q.top().fi, u = q.top().se;
		q.pop();
		if(du != d[u]) continue;
		for(int i = 0; i < edge[u].size(); i++) {
			if(vis[edge[u][i].se]) {
				continue;
			}
			int dv = edge[u][i].fi, v = edge[u][i].se;
			if(dv + du < d[v]) {
				d[v] = dv + du;
				q.push({d[v], v});
				// trace[v] = u;
			}
			
		}
	}
	cout << d[end] << ' ';
	// cout << trace[end] << endl;
}
vi A, b;
int x;
void solve() {
	cin >> n >> m >> p >> q;
	for(int i = 0; i < p; i++) {
		cin >> x;
		A.push_back(x);
	}
	for(int i = 0; i < q; i++) {
		cin >> x;
		b.push_back(x);
	}
	while(m--) {
		cin >> u >> v >> c;
		edge[u].push_back({c, v});
	}
	Dijkstra(1, n, A);
	Dijkstra(n, 1, b);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}