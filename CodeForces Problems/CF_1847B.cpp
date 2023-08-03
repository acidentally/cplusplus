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

int n, x;
void solve() {
	cin >> n;
	int a[n];
	cin >> a[0];
	int all = a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		all = all & a[i];
	}
	if(all >= 1) {
		cout << 1 << endl;
		return;
	}
	else {
		all = (1ull << 32) - 1;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			all = all & a[i];
			if(all == 0) {
				cnt++;
				all = (1ull << 32) - 1;
			}
		}
		cout << cnt << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}