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
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

pi segTree[4 * maxn] = {};
int a[maxn] = {};

void build(int id, int l, int r) {
	if(l == r) {
		segTree[id].se = a[l];
		// cout << id << ' ' << l << ' ' << a[l] << endl;
		return;
	}
	int mid = l + r >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);

	//Custom function for jointing 2 nodes.
	priority_queue<int> q;
	int t = id << 1;
	q.push(segTree[t].fi);
	q.push(segTree[t].se);
	q.push(segTree[t | 1].fi);
	q.push(segTree[t | 1].se);
	segTree[id].se = q.top();
	q.pop();
	segTree[id].fi = q.top();
	// cerr << id << ' ' << segTree[id].fi << ' ' << segTree[id].se << endl;
}
pi get(int id, int l, int r, int u, int v) {
	if(v < l || r < u) return {-1, -1};
	if(u <= l && r <= v) return segTree[id];

	int mid = l + r >> 1;
	pi get1 = get(id << 1, l, mid, u, v);
	pi get2 = get(id << 1 | 1, mid + 1, r, u, v);


	priority_queue<int> q;
	pi ans = mp(0, 0);
	q.push(get1.fi); q.push(get1.se);
	q.push(get2.fi); q.push(get2.se);
	ans.se = q.top(); q.pop();
	ans.fi = q.top();
	return ans;
}

int n, q;

void solve() {
	cin >> n >> q;
	int u, v;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);

	while(q--){
		cin >> u >> v;
		pi ans = get(1, 1, n, u, v);
		// cerr << u << v << endl;

		cout << ans.fi + ans.se << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("rdat.inp", "r", stdin);
	freopen("rdat.out", "w", stdout);
	solve();
}