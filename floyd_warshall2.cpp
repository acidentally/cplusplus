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
int const maxn = 3e6 + 10;
int const INF = (int)1e9 + 10;

vector<pi> a[maxn];
int d[maxn], trace[maxn] = {};
int n, m, s, t, u, v, z;
priority_queue< pi, vector<pi>, greater<pi> > q;

void Dijkstra() {
	while(!q.empty()) {
		int du = q.top().fi, u = q.top().se;
		q.pop();
		if(du != d[u]) continue;
		for(int i = 0; i < a[u].size(); i++) {
			int v = a[u][i].se, dv = a[u][i].fi;
			if(du + dv < d[v]) {
				d[v] = du + dv;
				q.push(pi(d[v], v));
				trace[v] = u;
			}
		}
	}
}
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> z;
		a[u].push_back({z, v});
		a[v].push_back({z, u});	
	}
	cin >> m;
	while(m--) {
		cin >> s >> t;
		for(int i = 1; i <= n; i++) d[i] = INF, trace[i] = 0;
		d[s] = 0;
		q.push({0, s});
		Dijkstra();
		if(d[t] == INF) {
			cout << -1 << endl;
			continue;
		}
		cout << d[t] << endl;
		stack<int> ans;
		while(trace[t] != 0) {
			ans.push(t);
			t = trace[t];
		}
		ans.push(t);
		while(!ans.empty()) {
			cout << ans.top() << ' ';
			ans.pop();
		}
		cout << endl;
	}
	
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}