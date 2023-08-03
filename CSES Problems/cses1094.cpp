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

int n;
void solve() {
	cin >> n;
	vi a; int x, ans = 0;
	cin >> x; a.push_back(x);
	for(int i = 1; i < n; i++) {
		cin >> x;
		ans += max(0ll, a[i - 1] - x);
		a.push_back(max(x, a[i - 1]));
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}