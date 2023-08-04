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

vi a[maxn] = {};
bool vis[maxn] = {};
stack<int> s;
int n = 0, k, minAns = INF, maxAns = 0, u, v;
void dfs(int k, int& s) {
	s++;
	vis[k] = true;
	for(int i = 0; i < a[k].size(); i++) {
		if(!vis[a[k][i]]) {
			dfs(a[k][i], s);
		}
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	n <<= 1;
	for(int i = 1; i <= n; i++) {
		int s = 0;
		if(!vis[i]) dfs(i, s);
		if(s >= 2) minAns = min(minAns, s);
		maxAns = max(maxAns, s);	
	}
	cout << minAns << ' ' << maxAns;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}