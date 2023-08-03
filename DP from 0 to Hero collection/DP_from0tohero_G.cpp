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
int const maxn 		= 	1e3 + 10;
int const INF 		= 	LLONG_MAX;

int n, a[maxn] = {}, len[maxn] = {};
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		len[i] = 1;
	}
	int ans = 1;
	for(int i = n - 2; i >= 0; i--) {
		int curMax = 0;
		for(int j = i + 1; j < n; j++) {
			if(a[j] > a[i]) curMax = max(curMax, len[j]);
		}
		len[i] = curMax + 1;
		ans = max(ans, len[i]);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}