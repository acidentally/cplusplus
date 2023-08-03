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

int n, x, y;

void solve() {
	cin >> n;
	multiset< pair<int, int> > a;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		a.insert({y, x});
	}
	multiset< pair<int, int> >::iterator ptr = a.begin();
	int ans = 0, cur = 0;
	while(ptr != a.end()) {
		if(cur <= ptr -> se) {
			ans++;
			cur = ptr -> fi;
		}
		ptr++;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}