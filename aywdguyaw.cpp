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

struct segmentTree {
	vi segTree;
	segmentTree(int n) : segTree(4 * n + 10);

	void updateTree(int id, int l, int r, int i, int val) {
		if(l > i || r < i) {
			return;
		} else if(l == r) {
			segTree[id] = val;
		}	
		else {
			int mid = l + r >> 1;
			updateTree(2 * id, l, mid, i, val);
			updateTree(2 * id + 1, mid + 1, r, val);

			segTree[id] = segTree[2 * id] ^ segTree[2 * id + 1];
		}

	}

};
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

}