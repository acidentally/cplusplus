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
typedef vector<pi>  	vpi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, m, u, v;
priority_queue<pi, vpi, greater<pi> > q;
void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> u >> v;
		if(u > v) {
			q.push({v, u});
		}
	}
	if(q.empty()) {
		cout << m; return;
	}
	int u_ = q.top().se, v_ = q.top().fi;
	q.pop();
	int ans = m;
	while(!q.empty()) {
		int v = q.top().fi, u = q.top().se;
		q.pop();
		if(v < u_) {
			u_ = max(u_, u);
		}
		else {
			ans += 2 * abs(u_ - v_);
			u_ = u;
			v_ = v;
		}
	}
	cout << ans + 2 * (u_ - v_);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("RIVER.INP", "r", stdin);
	freopen("RIVER.OUT", "w", stdout);
 	solve();
}