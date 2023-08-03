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

int const maxn 		=  	1e3+ 10; 
int const INF 		= 	LLONG_MAX;

int n, m, c, u, v;
int w[maxn] = {};
vi a[maxn] = {};
int dp[maxn][maxn] = {}; //số tiền nhiều nhất ở ngày i, tại tp j
void solve() {
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	memset(dp, -1, sizeof(dp));
	while(m--) {
		cin >> u >> v;
		a[u].pb(v);
	}
	int ans = 0;
	dp[0][1] = 0;
	for(int i = 0; i <= maxn; i++) {
		for(int j = 1; j <= n; j++) {
			// cerr << i << ' ' << j << endl;
			if(dp[i][j] == -1) continue;
			if(j == 1) {
				ans = max(ans, dp[i][j] - c * i * i);
			}
			for(auto s : a[j])  {
				dp[i + 1][s] = max(dp[i + 1][s], dp[i][j] + w[s]);
			}
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}