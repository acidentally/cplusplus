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
void solve() {
	cin >> n;
	priority_queue<pi, vector<pi>, greater<pi> > q;
	for(int i = 0; i < n; i++) {
		cin >> u >> v;
		q.push({v, u});
	}
	int ans = 1;
	v = q.top().fi; u = q.top().se;
	q.pop();
	while(!q.empty()) {
		if(q.top().se < v) q.pop();
		else {
			v = q.top().fi;
			q.pop();
			ans++;
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}