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
int const maxn = 2e5 + 10;
int const INF = 1e9 + 10;
int n;
void solve() {
	cin >> n;
	int x, cnt = 0, maxi = -INF;
	int sum[2] = {};
	if(n == 1) {
		cin >> x;
		cout << x << endl;
		return;
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x > 0) sum[i%2] += x;
		maxi = max(maxi, x);
		if(x < 0) cnt++;
	}
	if(cnt == n) {
		cout << maxi << endl;
		return;
	}
	cout << max(sum[0], sum[1]) << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	solve();
}