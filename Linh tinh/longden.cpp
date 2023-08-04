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
	int a[m];
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int l = 1, r = 1e9 + 10;
	while(l != r) {
		int ans = 0;
		int mid = l + r >> 1;
		for(int i = 0; i < m; i++) {
			ans += (a[i] - 1)/mid + 1;
		}
		if(ans > n) {
			l = mid + 1;
		}
		else r = mid;
	}
	cout << l;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}