#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define endl '\n'
#define INF (int)1e18

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	int cinTemp;

	vi mainArr, dp;
	int maxi = 0;

	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		mainArr.push_back(cinTemp);
		dp.push_back(0);
	}
	dp[n - 1] = mainArr[n - 1];
	for(int i = n - 2; i > -1; i--) {
		dp[i] = max(mainArr[i] + dp[i + 1], mainArr[i]);
		maxi = max(dp[i], dp[i + 1]); 
	}
	cout << maxi;
}