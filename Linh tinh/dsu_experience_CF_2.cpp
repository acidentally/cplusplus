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
 
int const maxn = 2e5 + 10;
int n, m, a, b;
string s;

int p[maxn], sz[maxn], val[maxn];
void init() {
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}
int find(int k) {
	if(k != p[k]) return find(p[k]);
	return k;
}
void join(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) {
		return;
	}
	if(sz[u] < sz[v]) {
		swap(u, v);
	}
	p[v] = u;
	val[v] -= val[u];
	if(sz[u] == sz[v]) sz[u]++;
}
void add(int u, int v) {
	u = find(u);
	val[u] += v;
}

int get(int u) {
	if(u == p[u]) {
		return val[u];
	}
	return val[u] + get(p[u]);
}
void solve() {
	cin >> n >> m;
	init();
	while(m--) {
		cin >> s;
		if(s == "add") {
			cin >> a >> b;
			add(a, b);
		} else if(s == "join") {
			cin >> a >> b;
			join(a, b);
		} else {
			cin >> a;
			cout << get(a) << endl;
		}	
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}