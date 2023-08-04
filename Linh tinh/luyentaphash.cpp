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
#define maxn 300005

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int n;

struct SegmentTree {
	vi segTree;
	SegmentTree(int n) : segTree(4 * n + 10){};

	void update(int id, int l, int r, int i, int val) {
		if(l > i || r < i) return;
		else if(l == r) {
			segTree[id] = val;
		} else {
			int mid = l + r >> 1;
			update(2 * id, l, mid, i, val);
			update(2 * id + 1, mid + 1, r, i, val);

			segTree[id] = segTree[2 * id] + segTree[2 * id + 1];
		}
	}
	int getVal(int id, int l, int r, int u, int v) {
		if(r < u || l > v){}
		else if(r >= u && l <= v) {
			return segTree[id];
		}
		else {
			int mid = l + r >> 1;
			if(mid >= v) return getVal(2 * id, l, mid, u, v);
			else if(mid < u) return getVal(2 * id, mid + 1, r, u, v);
			else {
				return getVal(2 * id, l, mid, u, v) + getVal(2 * id + 1, mid + 1, r, u , v);
			}
		}
	}
};

void solve() {
	SegmentTree st(n); 	
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	int op[m];
	for(int i = 0; i < n; i++) {
		cin >> x;

	}
}
