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

int const maxn 		= 	4e6 + 10; 
int const INF 		= 	LLONG_MAX;

int n, a[maxn] = {};
int dp[maxn][23] = {};
int F[maxn] = {};
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[a[i]][-1] = 1; 
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 10; j++) {
			if(mask & (1 << j)) {
				dp[mask][j] = dp[mask xor (1 << j)][j - 1];
			}
			else dp[mask][j] = dp[mask][j - 1] + dp[mask xor (1 << j)][j - 1];
		}
		F[mask] = dp[mask][9];
	}
	for(int i = 1; i <= n; i++) {
		cout << F[a[i]] << ' ';
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}