/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int compute(int u) {
	int ans = 0;
	while(u != 1) {
		u >>= 1;
		ans++;
	}
	return ans + 1;
}
int n, x, pre, temp;
void solve() {
	int ans = 0;
	cin >> n >> pre;
	for(int i = 1; i < n; i++) {
		cin >> x;	
		if(x >= pre) {
			pre = x;
			continue;
		}
		temp = pre - x;
		if(temp > (1 << ans) - 1) {
			ans = compute(temp);
		}
	}
	cout << ans << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}