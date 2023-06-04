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


int const maxn = 3e4 + 10;
int n, x, u, v, q;
vi a;
map<int, bool> st[4 * maxn + 10];

void build(int id, int l, int r) {
	if(l == r) {
		st[id][a[l]] = true;
		return;
	}
	int mid = l + r >> 1;
	build(2*id, l, mid);
	build(2*id + 1, mid + 1, r);

	map<int, bool>::iterator ptr = st[2*id].begin();
	while(ptr != st[2*id].end()) {
		st[id][ptr -> fi] = true;
		ptr++;
	}
	ptr = st[2*id + 1].begin();
	while(ptr != st[2*id + 1].end()) {
		st[id][ptr -> fi] = true;
		ptr++;
	}
}

map<int, bool> get(int id, int l, int r, int u, int v) {
	if(u > r || v < l) {
		return map<int, bool>();
	}
	if(u >= l && v <= r) {
		return st[id];
	}
	int mid = l + r >> 1;
	
}

void solve() {
	a.push_back(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	build(1, 1, n);
	cin >> q;
	while(q--) {
		cin >> u >> v;
		cout << get(1, 1, n, u, v).size() << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}