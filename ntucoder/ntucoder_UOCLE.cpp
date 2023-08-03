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

int a, b;
int sqr(int k) {
	int l = 0, r = (int)1e10;
	while(l != r) {
		int mid = l + r >> 1;
		if(mid * mid < k) {
			l = mid + 1;
		} else r = mid;
	}
	if(l * l > k) return l - 1;
	return l;
}
void solve() {
	cin >> a >> b;
	int k = sqr(a), dem = 0;
	if(k * k == a) dem = 1;
	cout << sqr(b) - sqr(a) + dem << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}