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
int const maxn 		= 	1e3 + 10;
int const INF 		= 	LLONG_MAX;

int n, x;
int T[maxn] = {}, inn[maxn] = {};
vi a[maxn] = {}, topo, before[maxn] = {};
string s;
pi dp[maxn] = {};
queue<int> q;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> T[i];
	}
	while(cin >> x) {
		if(x == 0) break;
		getline(cin, s);
		int cur = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == ' ') {
				if(cur != 0) {
					a[cur].pb(x);
					before[x].pb(cur);
					inn[x]++;
				}
				cur = 0;
				continue;
			}
			cur = (cur << 3) + (cur << 1) + s[i] - '0';
		}
		if(cur != 0) {
			a[cur].pb(x);
			before[x].pb(cur);
			inn[x]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(inn[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		topo.pb(u);
		for(auto k : a[u]) {
			inn[k]--;
			if(!inn[k]) q.push(k);
		}
	}
	int ans = T[1];
	for(auto k : topo) {
		for(auto i : before[k]) {
			dp[k].fi = max(dp[k].fi, dp[i].se);
		}
		dp[k].se = dp[k].fi + T[k];
		ans = max(ans, dp[k].se);
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		cout << dp[i].fi << ' ' << dp[i].se << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}