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
int const maxn = 1e5 + 10;

int n, q, u, v, x;
int a[maxn] = {}, cnt[maxn] = {};
set<int> s;
void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = x;
		cnt[x]++;
	}
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 0) s.insert(i);
	}

	while(q--) {
		cin >> u >> v;
		cnt[a[u]]--;
		cnt[v]++;
		if(cnt[a[u]] == 0) s.insert(a[u]);
		a[u] = v;
		if(cnt[a[u]] == 1) s.erase(a[u]);
		cout << *s.begin() << '\n';
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}