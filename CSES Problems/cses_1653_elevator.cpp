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
typedef pair<int, int> pi;

int n, x;
void solve() {
	cin >> n >> x;
	int w[n + 5];

	for(int i = 0; i < n; i++) {
		cin >> w[i];
	}
	int const maxn = 1 << n;
	pi dp[maxn + 10], settings;
	dp[0] = {1, 0};
	for(int i = 1; i < maxn; i++) {
		dp[i] = {100000, 100000};
		for(int j = 0; j < n; j++) {
			if((i >> j) & 1) {
				settings = dp[i ^ (1 << j)];
				if(settings.se + w[j] > x) {
					settings.fi++;
					settings.se = min(w[j], settings.se);
				}
				else {
					settings.se += w[j];
				}
				dp[i] = min(dp[i], settings);
			}
		}
	}
	// cout << dp[1].fi;
	cout << dp[maxn - 1].fi;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}