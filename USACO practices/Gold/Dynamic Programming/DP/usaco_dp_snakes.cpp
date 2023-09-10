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

int const maxn 		= 	1e6 + 1; 
int const INF 		= 	1e10;

int n, k;
int a[maxn] = {}, s[maxn] = {};
int dp[500][500] = {}; 
//lưu đáp án nhỏ nhất tìm được tại vị trí i, đã đổi j lần
void solve() {
	cin >> n >> k;
	int curMax = 0;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		curMax = max(curMax, s[i]);
		a[i] = s[i] + a[i - 1];
		dp[i][0] = curMax * i - a[i];
	}
	for(int idx = 2; idx <= n; idx++) 
	{

		for(int changes = 1; changes <= min(idx - 1, k); changes++) 
		{

			dp[idx][changes] = INF;
			curMax = s[idx];

			for(int i = idx - 1; i >= changes;  i--) 
			{
				curMax = max(curMax, s[i + 1]);
				dp[idx][changes] = min(dp[idx][changes],
					dp[i][changes - 1] + curMax * (idx - i) - a[idx] + a[i]);
			}
		}
	}
	int ans = INF;
	for(int i = 0; i <= k; i++) {
		cerr << dp[n][i] << endl;
		ans = min(ans, dp[n][i]);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("snakes.IN", "r", stdin);
	freopen("snakes.OUT", "w", stdout);
 	solve();
}