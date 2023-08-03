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

void solve() {
	int n, k, x;
	cin >> n >> k;
	int mini[k + 10][2] = {};
	int l[k + 10] = {}; 
	int cur = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		cur = i - l[x] - 1;
		l[x] = i;

		if(cur > mini[x][0]) mini[x][0] = cur;
		if(mini[x][0] > mini[x][1]) swap(mini[x][1], mini[x][0]);
	}
	for(int i = 1; i <= k; i++) {
		cur = n - l[i];
		if(cur > mini[i][0]) mini[i][0] = cur;
		if(mini[i][0] > mini[i][1]) swap(mini[i][1], mini[i][0]);
	}

	int ans = INF;
	for(int i = 1; i <= k; i++) {
		// cout << l[i] << endl;
		cur = max(mini[i][0], mini[i][1]/2);
		ans = min(ans, cur);
	}
	cout << ans << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}