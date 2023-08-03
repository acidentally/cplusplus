/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

int const maxn 		= 	1e5 + 10; 
// int const INF 		= 	LLONG_MAX;

int n, k;
int a[maxn] = {}, dp[maxn] = {};
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	for(int i = 2; i <= n; i++) {
		int curMax = 0;
		for(int j = 0; j < k; j++) {
			if(i - j < 1) break;
			curMax = max(a[i - j], curMax);
			dp[i] = max(dp[i], dp[i - j - 1] + (j + 1) * curMax);
		}
	}
	cout << dp[n];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("teamwork.IN", "r", stdin);
	// freopen("teamwork.OUt", "w", stdout);
 	solve();
}