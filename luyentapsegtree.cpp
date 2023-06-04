luytntap/*TRYING SO HARD LEARNING HOW TO CODE
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
int n, q, u, v, k;
int segTree[4*maxn + 20];
int a[maxn + 20], plus[maxn + 20];
void build(int id, int l, int r) {
	if(l == r) {
		segTree[id] = a[l];
	}
	int mid = l + r >> 1;
	build(2*id, l, mid);
	build(2*id + 1, mid + 1, r);
	segTree[id] = max(segTree(2*id), segTree(2*id + 1));
}

void get(int id, int l, int r, int u, int v) {
	if(u > r || v < l) {
		return 0;
	}
	if(u <= r && l >= v) {
		return segTree[id];
	}
	int mid = l + r >> 1;
	int get1 = get(2*id, l, mid, u, v);
	int get2 = get(2 * id + 1, l, mid + 1, u, v);
	return max(get1, get2);
}

solve() {
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int test;
	for(int i = 0; i < q; i++) {
		cin >> test;
		if(test == 1) {
			cin >> u >> v >> k;

		}
	}
}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}
