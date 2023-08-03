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

int n, y, d, h;
double compute(int base, int height, int diff) {
	return 1/2.0 * (base * height - base * (diff / double(height)) * diff);
}
void solve() {
	cin >> n;
	cin >> d >> h;
	int a[n + 10] = {};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	double ans = 0.0;
	int b[n + 10] = {};
	for(int i = 1; i < n; i++) {
		if(a[i - 1] + h > a[i]) {
			b[i - 1] = a[i - 1] + h - a[i];
		}
	}
	for(int i = 0; i < n; i++) {
		ans += compute(d, h, b[i]);
	}
	cout << fixed << setprecision(7) << ans << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}
