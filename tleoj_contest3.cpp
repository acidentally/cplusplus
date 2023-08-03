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

int n;
void solve() {
	cin >> n;
	int b[n + 10], cur = 0;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		cur ^= b[i];
	}
	if(cur != 0) {
		cout << -1 << end;
		return;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}