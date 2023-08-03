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


//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
int n, m, u, v;
string s;
vi p, den;
vector< pair<int, bool> > val;
void init() {
	p.resize(n + 1);
	val.resize(n + 1);
	den.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		den[i] = i;
		val[i] = make_pair(0, 0);
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
		val[u].fi -= val[v].fi;
	}
}
void add(int u, int v) {
	u = find(u);
	val[u].fi += v;
}
int get(int u, int ans = 0) {
	while(u != den[u]) {
		ans += val[u].fi;
		u = den[u];
	}
	return ans + val[u].fi;
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
			if(u == den[u]) den[u] = v;
			join(u, v);
		} else if(s == "get") {
			cin >> u;
			cout << get(u) << endl;
		}	
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	// cout << den[2];
}