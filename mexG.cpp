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
int const maxn = 5e5 + 10;
int const mod = 1e9 + 7;
int maxi = 0, n, a[maxn] = {}, ans = 0;
set<int> s;
int compute(int k) {
	int l = 1, r = mod + 100;
	int check = (ans % mod) * (k % mod) % mod + 1;
	while(l < r) {
		int mid = l + r >> 1;
		int curAns;
		if(mid > maxi) {
			curAns = mid;
		}
		else {
			curAns = s.lower_bound()
		}
	}
	return 1;
}
int q, k;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
		maxi = max(maxi, a[i]);
	}
	cin >> q;
	while(q--) {
		cin >> k;
		ans = compute(k);
		cout << ans << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}