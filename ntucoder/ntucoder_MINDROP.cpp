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

int n, pre, x;
void solve() {
	cin >> n >> pre;
	int ans = 0;
	int l = 0, r;
	for(int i = 1; i < n; i++) {
		cin >> x;
		if(x != pre) {
			ans = max(ans, i - l);
			l = i;
			pre = x;
		}
	}
	cout << n - ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}