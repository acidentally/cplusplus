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
template <class T>
T abs(T a, T b) {
	return max(a - b, b - a);
}

int n;
void solve() {
	cin >> n;
	int a[n + 10] = {};
	int dp[n + 10] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[n - 1] = abs(a[n] - a[n - 1]);
	for(int i = n - 2; i >= 1; i--){
		dp[i] = min(abs(a[i + 1] - a[i]) + dp[i + 1], 
					abs(a[i + 2] - a[i]) + dp[i + 2]);
	}
	cout << dp[1];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}