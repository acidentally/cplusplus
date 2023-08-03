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

int n, x, cinTemp;
void solve() {
	cin >> n >> x;
	vi a;
	int ans = 0, cur = 0, ptr = 0;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
		cur += cinTemp;
		while(cur > x) {
			cur -= a[ptr];
			ptr++;
		}
		if(cur == x) ans++;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}