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
int n, l, r, cnt = 0;
int a[1000010], b[1000010] = {};
void compute(deque<pi> q) {
	while(!q.empty()) {
		l = q.front().fi, r = q.front().se;
		q.pop_front();
		cnt = l;
		for(int i = r; i >= l; i--) {
			b[cnt] = a[i];
			cnt++;
		}
	}
}
void solve() {
	deque<pi> q;
	cin >> n;
	int l = 0;
	cin >> a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		if(a[i] > a[i - 1]) {
			if(l != i - 1) q.push_back({l, i - 1});
			l = i;
		}
	}
	if(l != n - 1) q.push_back({l, n - 1});
	compute(q);
	for(int i = 0; i < n; i++) {
		if(b[i] == 0) b[i] = a[i];
		if(b[i] <= b[i - 1]) {
			cout << -1;
			return;
		}
	}
	cout << q.size() << endl;
	while(!q.empty()) {
		cout << q.front().fi + 1 << ' ' << q.front().se + 1 << endl;
		q.pop_front();
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}