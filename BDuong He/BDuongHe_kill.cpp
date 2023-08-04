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
typedef pair<pi, int> 	pii;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, k;
vector<pii> a;
int u[maxn] = {}, v[maxn] = {};
int find(int val) {
	int l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(a[mid].fi.fi >= val) {
			r = mid;
		} else l = mid + 1;
	}
	return l;
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> u[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	a.pb({{0, 0}, 0});
	for(int i = 1; i <= n; i++) {
		a.pb({{u[i], v[i]}, i});
	}
	sort(all(a));

	for(int i = 1; i <= n; i++) {
		a[i].fi.se += a[i - 1].fi.se;
	}
	int ans[n + 10] = {};
	for(int i = 1; i <= n; i++) {
		int idx = find(a[i].fi.fi);
		ans[a[i].se] = a[i].fi.se - a[i - 1].fi.se + 
					   a[max(idx - 1, 0ll)].fi.se - 
					   a[max(idx - k - 1, 0ll)].fi.se;
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("KILL.INP", "r", stdin);
	freopen("KILL.OUT", "w", stdout);
 	solve();
}