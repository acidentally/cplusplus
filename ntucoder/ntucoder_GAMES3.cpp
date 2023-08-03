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
#define INF 1e9 + 100

int const maxn = 1e5 + 10;
int a[maxn] = {}, n, m, p, l;
pair<int, int> st[4 * maxn]; //fi max, se min

void build(int id, int l, int r) {
	if(l == r) {
		st[id].fi = a[l];
		st[id].se = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);

	st[id].fi = max(st[2*id].fi, st[2*id+1].fi);
	st[id].se = min(st[2*id].se, st[2*id+1].se);
}
int get(int id, int l, int r, int u, int v) {
	if(v < l || u > r) {
		return 0;
	}
	if(u <= l && r <= v || st[id].fi == st[id].se) {
		return st[id].fi;
	}
	int mid = l + r >> 1;
	return max(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}

void update(int id, int l, int r, int u, int v, int val) {
	if(v < l || u > r) {
		return;
	}
	else if((u <= l && r <= v) ); {
		st[id].fi = val;
		st[id].se = val;
		return;
	}
	int mid = l + r >> 1;

	update(2 * id, l, mid, u, v, val);
	update(2 * id + 1, mid + 1, r, u, v, val);
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int ans = 0;
	while(m--) {
		cin >> p >> l;
		ans = get(1, 1, n, p, p + l - 1) + 1;
		cout << ans << endl;
		update(1, 1, n, p, p + l - 1, ans);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}