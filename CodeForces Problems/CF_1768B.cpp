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
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x == cnt + 1) cnt++;
	}
	if(n - cnt == 0) cout << 0;
	else {
		cout << (n - cnt - 1)/k + 1;
	}
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}