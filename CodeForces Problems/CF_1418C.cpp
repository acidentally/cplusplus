/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define dub 			double
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				emplace_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define ins 			insert

typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	2e5 + 10;
int const INF 		= 	1e9;

int n;
int a[maxn] = {};
void solve() {
	cin >> n;
	int dp[n + 10][3][3] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << a[1] << endl;
		return;
	}
	#define friend 1
	#define me 0
	dp[1][friend][1] = a[1];
	dp[1][friend][2] = INF;
	dp[2][friend][1] = INF;
	dp[2][friend][2] = a[1] + a[2];
	dp[1][me][1] = dp[1][me][2] = INF;
	dp[2][me][1] = a[1]; dp[2][me][2] = INF;
	for(int i = 3; i <= n; i++) {
		dp[i][me][1] = min(dp[i - 1][friend][1], dp[i - 1][friend][2]);
		dp[i][me][2] = dp[i - 1][me][1];
		dp[i][friend][1] = a[i] + min(dp[i - 1][me][1], dp[i - 1][me][2]);
		dp[i][friend][2] = a[i] + dp[i - 1][friend][1];
	}
	int ans = INF;
	ans = min(ans, dp[n][me][2]);
	ans = min(ans, dp[n][me][1]);
	ans = min(ans, dp[n][friend][1]);
	ans = min(ans, dp[n][friend][2]);
	cout << ans << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}