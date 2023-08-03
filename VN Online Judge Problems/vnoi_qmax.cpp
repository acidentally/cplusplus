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


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int const maxn = 1e5 + 5;
int a[maxn];
int n, m, p, u, v, k;
int segTree[4*maxn + 10];
void build(int id, int l, int r) {
	if(l == r) {
		segTree[id] = a[l];
		return;
	} 
	int mid = l + r >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	segTree[id] = max(segTree[2 * id], segTree[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
	if(u > r || v < l) {
		return 0;
	} 
	if(u <= l && v >= r) {
		return segTree[id];
	}
	int mid = l + r >> 1;	
	int get1 = get(2 * id, l, mid, u, v);
	int get2 = get(2 * id + 1, mid + 1, r, u , v);
	return max(get1, get2);
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> k;
		a[u] += k;
		a[v + 1] -= k;
	}
	for(int i = 2; i <= n; i++) {
		a[i] = a[i] + a[i - 1];
	}
	build(1, 1, n);
	cin >> p;
	while(p--) {
		cin >> u >> v;
		cout << get(1, 1, n, u, v) << endl;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}