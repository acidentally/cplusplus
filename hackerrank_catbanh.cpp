/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int n, m;
void solve() {
	cin >> n >> m;
	// if(n < m) swap(n, m);
	// int ans = 0, height = 1;
	// for(int i = 1; i <= n; i++) {
	// 	ans++;
	// 	if(m * i == n * height) {
	// 		height++;
	// 	}
	// 	else if(m * i > n * height) {
	// 		ans++;
	// 		height++;
	// 	}
	// }
	// cout << ans;

	// OR

	cout << m + n - __gcd(m, n);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}


// d : mx - ny = 0
