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

int n, m, s, t, u, v;
vi p;
void init() {
	p.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
}
int find(int i) {
	if(i != p[i]) p[i] = find(p[i]);
	return p[i];
}
void connect(int u, int v) {
	u = find(u);
	v = find(v);
	p[u] = v;
}
void solve() {
	cin >> n >> m >> s >> t;
	init();
	while(m--) {
		cin >> u >> v;
		connect(u, v);
	}
	s = find(s);
	t = find(t);
	if(s == t) cout << "YES";
	else cout << "NO";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}