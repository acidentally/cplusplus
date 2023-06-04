/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)
#define INF 10000000000

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int n, q, d;
int const maxn = 100010;
int a[2*maxn + 10] = {}, segTree[4 * maxn] = {};
void build(int id, int l, int r) {
	if(l == r) {
		segTree[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	segTree[id] =  max(segTree[2 * id], segTree[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
	if(v < l || r < u) {
		return 0;
	}
	if(u <= l && r <= v) {
		return segTree[id];
	}
	int mid = l + r >> 1;
	return max(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}
int ans = INF;

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	build(1, 1, n);

	while(q--) {
		cin >> d;
		ans = INF;
		for(int j = 0; j < n - d + 1; j++) {
			ans = min(ans, get(1, 1, n, j + 1, j + d));
		}
		cout << ans << endl;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}