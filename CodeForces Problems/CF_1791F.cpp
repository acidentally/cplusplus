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
#define test int t; cin >> t; while(t--)
int const maxn = 2e5 + 10;
void sumDig(int& i) {
	int ans = 0;
	while(i) {
		ans += i % 10;
		i /= 10;
	}
	i = ans;
}
int n, q, a[maxn] = {};
int t, u, v;
void solve() {
	cin >> n >> q;
	set<int> idx;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] >= 10) idx.insert(i);
	}
	set<int>::iterator cur;
	while(q--) {
		cin >> t;
		if(t == 2) {
			cin >> u;
			cout << a[u] << endl;
		}
		if(t == 1) {
			cin >> u >> v;
			while(!idx.empty()) {
			 	cur = idx.lower_bound(u);
				if(*cur > v || cur == idx.end()) break;
				sumDig(a[*cur]);
				u = *cur + 1;
				if(a[*cur] < 10) idx.erase(cur);
			}
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	test
	solve();
}