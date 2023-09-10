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

int n;
void solve() {
	cin >> n;
	int a[n + 10] = {}, b[n + 10] = {}, dp[n + 10] = {};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		cin >> b[i];
	}
	dp[n - 1] = a[n - 1];
	if(n > 1) dp[n - 2] = min(a[n - 2] + a[n - 1], b[n - 2]);
	for(int i = n - 3; i >= 0; i--) {
		dp[i] = min(a[i] + dp[i + 1], b[i] + dp[i + 2]);
	}
	cout << dp[0];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}