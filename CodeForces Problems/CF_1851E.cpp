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
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, k, m, u, x;
int c[maxn] = {}, ans[maxn] = {}, par[maxn] = {};
bool check[maxn] = {}, vis[maxn] = {};
vi a[maxn] = {};
void dfs(int k) {
	vis[k] = true;
	if(a[k].size() == 0) {
		if(check[k]) ans[k] = 0;
		else ans[k] = c[k];
		return;
	}
	
	vis[k] = true;
	for(int i = 0; i < a[k].size(); i++) {
		if(!vis[a[k][i]]) dfs(a[k][i]);
		if(!check[a[k][i]]) ans[k] += ans[a[k][i]];
	}
	ans[k] = min(ans[k], c[k]);
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		a[i] = vi();
		check[i] = par[i] = ans[i] = vis[i] = 0;
		cin >> c[i];
	}
	while(k--) {
		cin >> x;
		check[x] = 1;
	}
	for(int i = 1; i <= n; i++) {
		cin >> m;
		while(m--) {
			cin >> u;
			a[i].pb(u);
			par[u]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!par[i]) dfs(i);
	}
	for(int i = 1; i <= n; i++) {
		if(check[i]) cout << 0 << ' ';
		else cout << ans[i] << ' ';
	}
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}