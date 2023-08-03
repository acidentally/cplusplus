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

int n, x;
void solve() {
	cin >> n;
	map<int, int> mp;
	bool found = false;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		mp[i] = x;
		if(!found && mp[mp[mp[i]]] == i) {
			cout << "<3" << endl;
			found = true;
		}
	}
	if(!found) cout << "</3" << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}