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
string trash = "Thanh phan ";
int n, m, u, v;
vi p, s;
vi mp[maxn];
void init() {
	p.resize(n + 1);
	s.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		s[i] = 1;
	}
}
int find(int i) {
	if(i != p[i]) p[i] = find(p[i]);
	return p[i];
}
void connect(int u, int v) {
	u = find(u);
	v = find(v);
	if(u != v) {
		p[max(u, v)] = min(u, v);
	}
}
void solve() {
	cin >> n >> m;
	init();
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		connect(u, v);
	}
	for(int i = 1; i <= n; i++) {
		mp[find(i)].push_back(i);
	}
	int cnt = 0;
	for(int i = 0; i <= n; i++) {
		if(!mp[i].empty()) {
			cnt++;
		}
	}
	if(cnt > 1) cout << "NO";
	else cout << "YES";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}