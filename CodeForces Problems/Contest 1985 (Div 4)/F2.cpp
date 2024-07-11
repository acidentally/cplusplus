#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int a[200005], c[200005];
void solve() {
	int h, n;
	cin >> h >> n;
	double temp = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		h -= a[i];
	}
	h = max(0, h);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		temp += a[i] * 1.0 / c[i];
	}
	double res = h / temp;
	ll ans = floor(res);
	while (true) {
		ll temp = 0;
		for (int i = 0; i < n; i++)
			temp += ans / c[i] * a[i];
		if (temp >= h) {
			cout << ans + 1 << endl;
			break;
		}
		ans++;
	}
}

signed main() {
	ll testcase;
	cin >> testcase;
	while (testcase--)
		solve();
	return 0;
}