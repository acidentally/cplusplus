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

int const maxn 		= 	1e6 + 10; 
int const INF 		= 	LLONG_MAX;

int n, P, maxVal, cur;
int a[maxn], tree[maxn] = {};
vi s;
void upd(int id) {
	int pos = id;
	while(pos <= maxVal) {
		tree[pos]++;
		pos += pos & -pos;
	}
}
int query(int id) {
	int ans = 0, pos = id;
	while(pos > 0) {
		ans += tree[pos];
		pos -= pos & -pos;
	}
	return ans;
}
int ans = 0;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> P;
	for(int i = 1; i <= n; i++) {
		a[i] -= P;
		a[i] += a[i - 1];
		s.pb(a[i]);
	}
	sort(all(s));
	unique(all(s));
	maxVal = s.size();
	for(int i = 1; i <= n; i++) {
		cur = lower_bound(all(s), a[i]) - s.begin() + 1;
		ans += (a[i] >= 0);
		//Fenwick computation
		ans += query(cur);
		upd(cur);
	}
	cout << ans;	
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("DOLLS.INP", "r", stdin);
	freopen("DOLLS.OUT", "w", stdout);
 	solve();
}