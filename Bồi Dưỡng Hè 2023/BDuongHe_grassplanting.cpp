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

int n, u, v, ans = 0;
vi a[maxn];
bool color[maxn] = {};
void dfs(int k, int par) {
	int child = 0;
	for(int i = 0; i < a[k].size(); i++) {
		if(a[k][i] == par) continue;
		child++;
		dfs(a[k][i], k);
	}
	// cout << k << ' ' << child << endl;
	if(par != -1) ans = max(ans, child + 2);
	else ans = max(ans, child + 1);
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1, -1);
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}