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

int const maxn = 5e4 + 10;
int n, q, x, y, k, m;

struct node {
	int val = 0, lazy = 0;
} st[4 * maxn];

void down(int id) {
	int z = st[id].lazy, t = 2 * id;
	st[t].val += z;
	st[t].lazy += z;
	st[t + 1].val += z;
	st[t + 1].lazy += z;
	st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int nVal) {
	if(r < u || v < l) return;
	if(u <= l && r <= v) {
		st[id].val += nVal;
		st[id].lazy += nVal;
		return;
	}
	int mid = l + r >> 1;
	down(id);
	update(2 * id, l, mid, u, v, nVal);
	update(2 * id + 1, mid + 1, r, u, v, nVal);
	st[id].val = max(st[2 * id].val, st[2 * id + 1].val);
}
int get(int id, int l, int r, int u, int v) {
	if(r < u || v < l) return -1;
	if(u <= l && r <= v) {
		return st[id].val;
	}
	down(id);
	int mid = l + r >> 1;
	int get1 = get(2 * id, l, mid, u, v);
	int get2 = get(2 * id + 1, mid + 1, r, u, v);
	return max(get1, get2);
}
void solve() {
	cin >> n >> m;
	int c;
	while(m--) {
		cin >> c;
		if(c == 0) {
			cin >> x >> y >> k;
			update(1, 1, n, x, y, k);
		} else if(c == 1) {
			cin >> x >> y;
			cout << get(1, 1, n, x, y) << endl;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}