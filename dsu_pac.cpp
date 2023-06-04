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


int n, m, u, v;
vi p, s;
void init() {
	p.resize(n + 1);
	s.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		s[i] = 1;
	}
}
int find(int u) {
	if(u == p[u]) return u;
	p[u] = find(p[u]);
	return p[u];
}
void connect(int u, int v) {
	u = find(u);
	v = find(v);
	if(u != v) {
		p[u] = v;
		s[v] += s[u];
	}
}
void solve() {
	cin >> n >> m;
	init();
	while(m--) {
		cin >> u >> v;
		connect(u, v);
	}
	if(s[find(1)] == n) cout << "YES";
	else cout << "NO";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}