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

int x, y;
void solve() {
	cin >> y >> x;
	if(x == y) {
		cout << x * x + 1 - y << endl;
	}
	else if(x > y) {
		if(!(x % 2)) cout << (x - 1) * (x - 1) + y << endl;
		else cout << x * x - y + 1 << endl;
	}
	else if(x < y) {
		if(y % 2) cout << (y - 1) * (y - 1) + x << endl;
		else cout << y * y - x + 1 << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}
