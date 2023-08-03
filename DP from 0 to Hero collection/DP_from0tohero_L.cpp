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
int const maxn 		= 	1e6 + 10;
int const INF 		= 	LLONG_MAX;

int n, x, k;
int a[maxn] = {}, min_[maxn] = {};

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = x + a[i - 1];
		min_[i] = min(min_[i - 1], a[i]);
	}
	int ans = -INF;
	for(int i = n; i >= k; i--) {
		ans = max(ans, a[i] - min_[i - k]);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}