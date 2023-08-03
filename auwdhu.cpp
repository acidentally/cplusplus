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
int n, m, q, l, r;
char x;

void solve() {
	cin >> n >> m >> q;
	bool a[n + 10];
	for(int i = 0; i < n; i++) {
		cin >> x;
		a[i] = x - '0';
	}
	while(m--) {
		cin >> l >> r;
		q.push({l, r});
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
