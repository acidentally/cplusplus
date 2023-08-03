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

int n, k, x;
void solve() {
	cin >> n >> k;
	int sum = 0, cnt = 1, pre;
	priority_queue<int> q;
	int a[n + 10]; cin >> pre;
	for(int i = 1; i < n; i++) {
		cin >> x;
		sum += abs(x - pre);
		q.push(abs(x - pre));
		pre = x;
	}
	cnt = 1;
	while(!q.empty() && cnt < k) {
		cnt++;
		sum -= q.top();
		q.pop();
	}
	cout << sum << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}