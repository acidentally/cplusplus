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
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, u, v;
bool vis[maxn] = {};
vi a[maxn] = {};
int h[maxn] = {};
int maxi[2] = {};
int curMax = 0;
void dfs(int k, int par, int d) {
	vis[k] = true;
	curMax = max(curMax, d);
	
	for(auto i : a[k]) {
		if(vis[i] || i == par) continue;
		else {
			dfs(i, k, d + 1);
		} 
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	for(auto i : a[1]) {
		curMax = 0;
		dfs(i, 1, 1);
		if(curMax > maxi[0]) {
			maxi[0] = curMax;
			if(maxi[0] > maxi[1]) swap(maxi[0], maxi[1]);
		}
	}
	int ans = maxi[1];
	if(a[1].size() == 1) cout << ans;
	else cout << ans + maxi[0];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}