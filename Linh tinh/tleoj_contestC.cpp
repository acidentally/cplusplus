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
	int a[n + 1][n + 1] = {};
	int dp[n + 1][n + 1] = {};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = n; i >= 1; i--) dp[n][i] = a[n][i];

	for(int i = n - 1; i >= 1; i--) {
		for(int j = 1; j <= i; j++) {
			dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
			// cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	}

	cout << dp[1][1];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}