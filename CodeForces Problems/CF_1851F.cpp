/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

struct node{
	node* child[2];
	int idx, cnt;
	node() {
		child[0] = child[1] = NULL;
		idx = cnt = 0;
	}
} *root;

int n, k, ans = 0;
int id1 = 0, id2 = 0;
struct Trie {
	Trie() {
		root = new node();
	}
	void add(int x, int id) {
		node *pos = root;
		for(int i = k; i >= 0; i--) {
			int c = (x >> i) & 1;
			if(pos -> child[c] == NULL) {
				pos -> child[c] = new node();
			}
			pos = pos -> child[c];
			pos -> cnt++;
		}
		pos -> idx = id;
	}
	void remove(int x) {
		node *pos = root;
		for(int i = k; i >= 0; i--) {
			int c = (x >> i) & 1;
			pos = pos -> child[c];
			pos -> cnt--;
		}
	}
	pi find(int x) {
		node *pos = root, *cur;
		int res = 0;
		for(int i = k; i >= 0; i--) {
			int c = (x >> i) & 1;
			cur = pos -> child[c];
			if(cur != NULL && cur -> cnt > 0) {
				pos = pos -> child[c];
				res = (res << 1) | 1;
			}
			else {
				pos = pos -> child[1 - c];
				res = res << 1;
			}
		}
		return mp(res, pos -> idx);
	}
} tri;

int a[maxn] = {};
void solve() {
	cin >> n >> k;
	k--;
	tri = Trie();
	ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		tri.add(a[i], i);
	}
	for(int i = 1; i <= n; i++) {
		tri.remove(a[i]);
		pi curAns = tri.find(a[i]);
		if(curAns.fi >= ans) {
			ans = curAns.fi;
			id1 = i; id2 = curAns.se;
		}
		tri.add(a[i], i);
	}
	int res = 0;
	for(int i = k; i >= 0; i--) {
		int u = (a[id1] >> i) & 1, v = (a[id2] >> i) & 1;
		res = (res << 1) | ((u ^ v) ? 1 : !u);
	}
	cout << id1 << ' ' << id2 << ' ' << res << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}