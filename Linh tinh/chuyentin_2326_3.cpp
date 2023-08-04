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

int m, n, ans = 0;
void solve() {
	cin >> m >> n;
	int a[m];
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a + m);
	n = min(m, n);
	for(int i = m - 1; i > m - n - 1; i--) {
		ans = max(ans, (m - i) * a[i]);
	}
	cout << ans;

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}