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
int const maxn 		= 	1e5 + 10; 
int const INF 		= 	LLONG_MAX; 

int n, u, v;
vi a[maxn] = {};
vector<vi> dp(maxn, vi(2, -1));
void dfs(int k, int par, bool On) {
	if(dp[k][On] != -1) return;
	dp[k][On] = On ? 1 : 0;
	bool visAny = 0;
	if(On) {
		for(auto s : a[k]) {
			if(s == par) continue;
			visAny = 1;
			dfs(s, k, 1);
			dfs(s, k, 0);
			dp[k][1] += min(dp[s][1], dp[s][0]);
		}
		return;
	}
	else {
		for(auto s : a[k]) {
			if(s == par) continue;
			visAny = 1;
			dfs(s, k, 1);
			dp[k][0] += dp[s][1];
		}
	}
	if(!visAny) {
		dp[k][1] = 1;
		dp[k][0] = 0;
		return;
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
	dfs(1, -1, 1); dfs(1, -1, 0);
	cout << min(dp[1][1], dp[1][0]);
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}