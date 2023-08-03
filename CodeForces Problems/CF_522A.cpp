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
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

void lower(string& s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] > 'Z') {
			s[i] = s[i] - 32;
		}
	}
}
int n;
string s1, trash, s2;
unordered_map<string, int> mp;
vi a[300] = {};
int h[300] = {}, ans = 0, cnt = 1;
bool vis[300] = {};
void dfs(int k, int par, int d) {
	vis[k] = true;
	ans = max(ans, d);
	for(auto i : a[k]) {
		if(vis[i] || i == par) continue;
		dfs(i, k, d + 1);
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> trash >> s2;
		lower(s1); lower(s2);

		if(mp[s2] == 0) mp[s2] = cnt++;
		if(mp[s1] == 0) mp[s1] = cnt++;
		a[mp[s2]].pb(mp[s1]);
	}

	dfs(1, -1, 1);
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}