/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

typedef pair<int, int> pi;
int x1, x2, y, yy, z1, z2, res;
pi ans, ans2;
pi intersect(pi a, pi b) {
	return {max(a.fi, b.fi), min(a.se, b.se)};
}
void solve() {
	cin >> x1 >> x2 >> y >> yy >> z1 >> z2;
	ans = intersect({x1, x2}, {y, yy});
	ans2 = intersect(ans, {z1, z2});
	res = ans2.se - ans2.fi + 1;
	if(res <= 0) {
		cout << 0 << endl;
	}
	else cout << res << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}