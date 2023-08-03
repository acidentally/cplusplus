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
#define dub 			double
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				emplace_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define ins 			insert

typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
typedef pair<int, pi> 	ppi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e6 + 10; 
int const INF 		= 	LLONG_MAX;

struct node {
	node* child[2];
	int exist, val;
	node() {
		child[0] = child[1] = NULL;
		exist = 0;
	}
} *root;

struct Trie {
	Trie() {
		root = new node();
	}
	void add(int x) {
		node *pos = root;
		for(int i = 30; i >= 0; i--) {
			int c = (x >> i) & 1;
			if(pos -> child[c] == NULL) pos -> child[c] = new node();
			pos = pos -> child[c];
		}
		pos -> exist++;
		pos -> val = x;
	}

	int find(int x) {
		node *pos = root;
		int res = 0;
		for(int i = 30; i >= 0; i--) {
			int c = (x >> i) & 1;
			if(pos -> child[1 - c]) {
				res = res << 1 | 1;
				pos = pos -> child[1 - c];
			}
			else {
				pos = pos -> child[c];
				res <<= 1;
			}
		}
		return res;
	}
} tri;

int n, a[maxn] = {};
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			tri.add(a[i] ^ a[j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int cur = tri.find(a[i]);
		if(cur >= ans) {
			ans = cur;
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}