/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define all(a) a.begin(),a.end()
typedef pair<int, int> pi;
int n, m, u, v;
vector<pi> a;
int lower(int k) {
	if(a[n].fi < k) {
		return n + 1;
	}
	int l = 0, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(a[mid].fi < k) {
			l = mid + 1;
		} else r = mid;
	}
	return l;
}

void solve() {
	cin >> n >> m;
	a.push_back({0,0});
	for(int i = 0; i < n; i++) {
		cin >> u >> v;
		a.push_back({v, u});
	}
	sort(all(a));
	for(int i = 1; i <= n; i++) {
		a[i].se += a[i-1].se;
	}
	while(m--) {
		cin >> u >> v;
		cout << a[lower(v + 1) - 1].se - a[lower(u) - 1].se << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// solve();
	cout << 0;
}