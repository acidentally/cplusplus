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
 
int n, x;
int a[200] = {}, dp[maxn] = {};
void solve() {
	cin >> n >> x;
	memset(dp, 1e6 + 10, sizeof(dp));
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]] = 1;
	}
 
	for(int i = 1; i <= x; i++) {
		for(int j = 0; j < n; j++) {
			if(i - a[j] <= 0 || dp[i - a[j]] == 0) continue;
			dp[i] = min(dp[i], dp[i - a[j]] + 1);
		}
	}
	cout << ((dp[x] > 1e6) ? -1 : dp[x]);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}