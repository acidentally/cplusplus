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

int n, t, x;
void solve() {
	cin >> n;
	bool a[n][n] = {};
	for(int i = 0; i < n; i++) {
		cin >> t;
		while(t--) {
			cin >> x;
			a[i][x] = 1;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;`
	while(tc--) {
		solve();
	}
}