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

int n, m, maxSum;
void solve() {
	cin >> n >> m >> maxSum;
	int a[n + 10] = {}, b[m + 10] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		b[i] += b[i - 1];
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		int cur = maxSum - a[i];
		if(cur < 0) break;
		int l = 1, r = m;
		while(l < r) {
			int mid = l + r >> 1;
			if(b[mid] > cur) r = mid;
			else l = mid + 1;
		}
		if(b[l] > cur) l--;
		if(l > m) continue;
		// cout << i << ' ' << l << endl;
		ans = max(ans, i + l);
	}
	cout << ans << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}