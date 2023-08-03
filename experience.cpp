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
struct dsu_node {
	int val;
	dsu_node* Owner;
	dsu_node() {
		val = 0;
		Owner = NULL;
	}
	dsu_node* createNode() {
		dsu_node* temp = new dsu_node;
		temp -> val = 0;
		temp -> Owner = nullptr;
		return temp;
	}
	void connect(dsu_node* node1, dsu_node* node2) {
		while(node1 -> Owner != nullptr) {
			node1 = node1 -> Owner;
		}
		while(node2 -> Owner != nullptr) {
			node2 = node2 -> Owner;
		}
		if(node1 == node2) return;
		else {
			node1 -> Owner = createNode();
			node2 -> Owner = node1 -> Owner;
		}
	}
	void add(int v, dsu_node* u) {
		while(u -> Owner) u = u -> Owner;
		u -> val += v;
	}
	int get(dsu_node* u) {
		int ans = 0;
		while(u -> Owner) {
			ans += u -> val;
			u = u -> Owner;
		}
		return ans + u -> val;
	}
};
dsu_node* d[maxn];
int n, m, u, v;
string s;
void init() {
	for(int i = 1; i <= n; i++) {
		d[i] -> val = 0;
		d[i] -> Owner = NULL;
	}
}

void solve() {
	cin >> n >> m;
	init();
	while(m--) {
		cin >> s;
		if(s == "join") {
			cin >> u >> v;
			connect(d[u], d[v]);
		} else if(s == "add") {
			cin >> u >> v;
			add(v, d[u]);
		} else if(s == "get") {
			cin >> u;
			get(d[u]);
		}
 	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}