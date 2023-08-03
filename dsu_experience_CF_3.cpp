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
string s;
 
vi p, val, den;
 
void init() {
	p.push_back(0);
	val.push_back(0);
	den.push_back(0);
	for(int i = 1; i <= n; i++) {
		p.push_back(i);
		den.push_back(i);
		val.push_back(0);
	}
}
int find(int k) {
	if(k != p[k]) p[k] = find(p[k]);
	return p[k];
}
void join(int u, int v) {
	u = find(u);
	v = find(v);
	if(u != v) {
		p[u] = v;
		den[u] = v;
		val[u] -= val[v];
	}
}
void add(int u, int v) {
	u = find(u);
	val[u] += v;
}
int get(int u) {
	int ans = 0;
	while(u != den[u]) {
		ans += val[u];
		u = den[u];
	}
	return ans + val[u];
}
void solve() {
	cin >> n >> m;
	init();
	while(m--) {
		cin >> s;
		if(s == "add") {
			cin >> u >> v;
			add(u, v);
		} else if(s == "join") {
			cin >> u >> v;
			join(u, v);
		} else {
			cin >> u;
			cout << get(u) << endl;
		}	
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}