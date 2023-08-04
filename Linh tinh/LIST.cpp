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
int const mod 		= 	1e9 + 7;

int const maxn 		= 	5e5 + 10; 
int const INF 		= 	1e9;

struct node {
	int prev, nxt;
	node() {
		prev = 0, nxt = INF;
	}
};
node a[maxn] = {};
void delNode(int u) {
	//pre -> u -> nxt
	int pre = a[u].prev, nxt = a[u].nxt;
	a[pre].nxt = nxt;
	if(nxt != INF) {
		a[nxt].prev = pre;
	}
}
void connect(int u, int v) {
	int pre = a[v].prev;
	a[pre].nxt = u;
	a[u].nxt = v;
	a[v].prev = u;
	a[u].prev = pre;
}
int n, m, u, v, b[maxn] = {}, c[maxn] = {};
char x;
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		a[i].nxt = i + 1;
		a[i].prev = i - 1;
	}
	a[n].nxt = INF;
	while(m--) {
		cin >> x >> u >> v;
		if(x == 'B') swap(u, v);
		delNode(u);
		connect(u, v);
	}
	int st = 0, idx = 1, res = 0;
	while(a[st].nxt != INF) {
		st = a[st].nxt;
		b[idx++] = st;
		// cout << st << endl;
	}
	for(int i = 1; i <= n; i++) {
		int j = lower_bound(c + 1, c + res + 1, b[i]) - c;
		c[j] = b[i];
		res = max(res, j);
	}
	cout << n - res;
	// cout << moves;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}