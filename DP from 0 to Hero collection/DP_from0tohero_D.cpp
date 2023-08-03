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
int const modn 		= 	14062008;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

bool check[maxn] = {};
int dp[maxn] = {};
int n, k, x;
void solve() {
	cin >> n >> k;
	while(k--) {
		cin >> x;
		check[x] = true;
	}
	for(int i = 1; i <= n; i++) dp[i] = 0;
	if(!check[n]) dp[n] = 1;
	if(!check[n - 1]) dp[n - 1] = 1;
	for(int i = n - 2; i >= 1; i--) {
		if(check[i]) continue;
		dp[i] = (dp[i + 1] % modn + dp[i + 2] % modn) % modn;
	}
	cout << dp[1];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}