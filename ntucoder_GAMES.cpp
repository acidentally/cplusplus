/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")
#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int n, m, x, p, l;
int const maxn = 100010;
int a[maxn + 10];
int st[4 * maxn + 10] = {};

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(2*id, l, mid);
	build(2*id + 1, mid + 1, r);

	st[id] = max(st[2*id + 1], st[2*id]);
}

int get(int id, int l, int r, int u, int v) { 
	if(v < l || u > r) {
		return 0;
	}
	if(u <= l && r <= v) {
		return st[id];
	}
	int mid = l + r >> 1;
	int get1 = get(2*id, l, mid, u, v);
	int get2 = get(2*id+1, mid+1, r, u, v);
	return max(get1, get2);
}
void update(int id, int l, int r, int u, int v, int val) {
	if(v < l || u > r) {
		return;
	}
	if(l == r) {
		st[id] = val;
		return;
	}
	int mid = l + r >> 1;

	update(2 * id, l, mid, u, v, val);
	update(2 * id + 1, mid + 1, r, u, v, val);

	st[id] = max(st[2*id + 1], st[2*id]);
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int ans;

	for(int i = 0; i < m; i++) {
		cin >> p >> l;
		ans = get(1, 1, n, p, p + l - 1) + 1;
		update(1, 1, n, p, p + l - 1, ans);
		cout << ans << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
    