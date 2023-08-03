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

int const maxn 		= 	2e5 + 10; 
int const INF 		= 	LLONG_MAX;

int n, k, x, cur, cnt = 0;
void solve() {
	cin >> n >> k >> x;
	priority_queue<int, vi, greater<int> > q, q2;
	for(int i = 0; i < n; i++) {
		cin >> cur;
		q.push(cur);
	}
	int pre = q.top();
	q.pop();
	while(!q.empty()) {
		int u = q.top(); q.pop();
		if(u > x + pre) {
			q2.push((u - pre - 1) / x);
			cnt++;
		}
		pre = u;
	}

	int ans = q2.size() + 1;
	while(!q2.empty()) {
		int u = q2.top(); q2.pop();
		if(k >= u) {
			ans--;
			k -= u;
		}
		else break;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("groups.inp", "r", stdin);
	freopen("groups.out", "w", stdout);
 	solve();
 	// cout << LLONG_MAX;
}