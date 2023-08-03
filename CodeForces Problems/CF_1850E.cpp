/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

// #define int 			long long
#define int 			unsigned long long
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

int sqr(int k) {
	return k * k;
}
int n, c;
int sz[maxn] = {};
void solve() {
	cin >> n >> c;
	int maxi = 0;
	for(int i = 1; i <= n; i++) {
		cin >> sz[i];
		maxi = max(maxi, sz[i]);
	}
	int l = 1, r = sqrt(c/n) + 100;
	while(l != r) {
		int mid = l + r >> 1;
		int cur = 0;
		for(int i = 1; i <= n; i++) {
			cur += sqr(sz[i] + 2 * mid);
		}
		// cout << cur << endl;
		if(cur >= c) {
			r = mid;
		} else l = mid + 1;
	}
	cout << l << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}