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

void connect(int u, int v, int& groups) {
	u = find(u); v = find(v);
	if(u != v) {
		groups--;
		p[u] = v;
	}
}

void solve() {
	cin >> n >> m;
	init();
	int dsuTotalGroups = n;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		connect(u, v, dsuTotalGroups);
		if(dsuTotalGroups == 1) {
			cout << i;
			exit(0);
		} 
	}
	if(dsuTotalGroups != 1) {
		cout << "FAILURE";
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}