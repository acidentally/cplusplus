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
typedef pair<int, int> pi;
int n, S;
void solve() {
	cin >> n >> S;
	int a[n + 10] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1, r = n;
	priority_queue<pi> ans;
	while(l <= r) {
		// cout << l << ' ' << r << endl;
		priority_queue<int, vi, greater<int> > q;
		int mid = l + r >> 1;

		for(int i = 1; i <= n; i++) {
			q.push(a[i] + i * mid);
		}

		int k = mid, sum = 0;
		while(k--) {
			sum += q.top();
			q.pop();
		}

		if(sum == S) {
			cout << mid << ' ' << sum;
			return;
		}
		if(sum <= S) {
			// cout << sum << endl;
			ans.push({mid, sum});
			l = mid + 1;
		} 
		else r = mid - 1; 
	}
	if(ans.empty()) {
		cout << "0 0";
		return;
	}
	cout << ans.top().fi << ' ' << ans.top().se;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
