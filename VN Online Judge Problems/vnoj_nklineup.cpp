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
#define INF 1e18


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int const maxn = 50010;
int segTreeMin[4 * maxn + 10], segTreeMax[4 * maxn + 10];
int a[maxn + 10] = {};
int n, q, u, v;

void build(int id, int l, int r) {
	if(l == r) {
		segTreeMin[id] = segTreeMax[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	segTreeMin[id] = min(segTreeMin[2*id + 1], segTreeMin[2*id]);
	segTreeMax[id] = max(segTreeMax[2*id + 1], segTreeMax[2*id]);
}


int getmin(int id, int l, int r, int u, int v) {
	if(v < l || u > r) {
		return 1000010;
	}
	if(u <= l && r <= v) {
		return segTreeMin[id];
	}
	int mid = l + r >> 1;
	int get1 = getmin(2*id, l, mid, u, v);
	int get2 = getmin(2*id +1, mid + 1, r, u , v);
	return min(get1, get2);
}

int getmax(int id, int l, int r, int u, int v) {
	if(v < l || u > r) {
		return 0;
	}
	if(u <= l && r <= v) {
		return segTreeMax[id];
	}
	int mid = l + r >> 1;
	return max(getmax(2*id, l, mid, u, v), getmax(2*id + 1, mid + 1, r, u, v));
}

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];	
	}

	build(1, 1, n);

	for(int i = 0; i < q; i++) {
		cin >> u >> v;
		cout << getmax(1, 1, n, u, v) - getmin(1, 1, n, u, v) << endl;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}