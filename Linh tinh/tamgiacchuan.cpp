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

int a, b;

pair<int, int> binarySearch(int n) {
	n--;
	n <<= 1;
	int ans = sqrt(n);
	while(ans * ans - ans <= n) {
		ans++;
	}
	ans--;
	return {ans * (ans - 1) / 2 + 1, ans};
}

void solve() {
	cin >> a >> b;
	if(a > b) swap(a, b);
	pair<int, int> ya = binarySearch(a);
	pair<int, int> yb = binarySearch(b);
	if(a - ya.fi == b - yb.fi || ya.fi + ya.se - 1 - a == yb.fi + yb.se - 1 - b || ya.se == yb.se) {
		cout << 1 << ' ';
		pair<int, int> yc;
		if(ya.se == yb.se) {
			yc.se = yb.fi - ya.fi + yb.se;
			int temp = b - a + yb.se;
			cout << temp * (temp - 1)/2 + 1 + b - yb.fi;
		} else {
			yc.se = yb.se;
			int temp = 1;
			if(a - ya.fi < b - yb.fi) {
				temp = -1;
			}
			cout << b + temp * (yb.se - ya.se);
		}
		cout << endl;
	}
	else cout << 0 << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}