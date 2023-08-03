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

int n, k;
void solve() {
	cin >> n >> k;
	int a[n + 10] = {};
	priority_queue<int> pos, neg;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] > 0) pos.push(a[i]);
		if(a[i] < 0) neg.push(-a[i]);
	}
	int minDis = 0, cur = 0;
	while(!pos.empty()) {
		int it = k;
		cur = max(cur, pos.top());
		minDis += 2 * pos.top();
		while(!pos.empty() && it--) {
			pos.pop();
		}
	}
	while(!neg.empty()) {
		int it = k;
		cur = max(cur, neg.top());
		minDis += 2 * neg.top();
		while(!neg.empty() && it--) {
			neg.pop();
		}
	}
	minDis -= cur;
	cout << minDis << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}