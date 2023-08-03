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

int n, cnt[maxn] = {}, child[maxn] = {}, u;
bool vis[maxn] = {};
queue<pi> q;
void dfs(int k, int st) {
	if(vis[k]) {
		q.push({st, k});
		return;
	}
	vis[k] = true;
	dfs(child[k], st);
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> u;
		child[i] = u;
		cnt[u]++;
	}
	int st = n;
	for(int i = 1; i <= n; i++) {
		if(!cnt[i]) {
			dfs(i, i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dfs(i, i);
		}
	}
	if(q.size() == 1 && q.front().fi == q.front().se) {
		cout << 0;
		return;
	}
	cout << q.size() << endl;
	st = q.front().fi;
	while(!q.empty()) {
		u = q.front().se;
		q.pop();
		if(q.empty()) {
			cout << u << space << st;
			return;
		}
		cout << u << ' ' << q.front().fi << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}