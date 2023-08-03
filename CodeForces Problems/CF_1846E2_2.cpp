/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int const maxn = 1e18 + 1;
int const sqrmaxn = 1e9 + 10;
int n;
// set<int> s;
bool binary(int l, int r, int exp) {
	int mid = l + r >> 1;
	int sum = 0, cur = 1;
	for(int i = 0; i <= exp; i++) {
		if(sum >= maxn - cur || ((cur >= maxn / mid) && i != exp)) {
			if(l == r) return 0;
			return binary(l, mid, exp);
		}
		sum += cur;
		cur *= mid;
		// if(i >= 2) s.insert(sum);
	}
	if(sum == n) return true;
	if(l >= r) return false;
	if(sum > n) return binary(l, mid, exp);
	if(sum < n) return binary(mid + 1, r, exp);
	return 0;
}
void solve() {
	cin >> n;
	for(int i = 2; i <= 64; i++) {
		if(binary(2, sqrmaxn, i)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}