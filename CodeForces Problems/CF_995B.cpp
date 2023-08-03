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
unordered_map<int, int> mp;
void solve() {
	cin >> n;
	int k = 2 * n, a[k + 10];
	set<int> st;
	for(int i = 1; i <= k; i++) {
		cin >> a[i];
		if(a[i] == a[i - 1]) mp[a[i]] = 0;
		else mp[a[i]] = i;
	}
	int ans = 0;
	// exit(0);
	for(int i = 1; i <= k; i++) {
		if(mp[a[i]] == 0) {
			i++;
			continue;
		}
		else if(st.size() == 0) {
			ans += mp[a[i]] - i - 1;
			st.insert(mp[a[i]]);
		}
		else {
			int ka = mp[a[i]];
			int p2 = st.upper_bound(ka) - st.begin();
			ans += mp[a[i]] - i - p2;
			st.insert(mp[a[i]]);
		}
		mp[a[i]] = 0;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}