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

int const INTMAX = 1e18 + 100;
int const maxn = 1e9 + 1;
int n;
bool binarySearch(int l, int r, int exp) {
	// if(l >= r) return 0;
	if(l > r) return 0;
	int mid = (l + r) >> 1;
	int sum = 0, cur = 1;
	for(int i = 0; i <= exp; i++) {
		// cout << sum << " ";
		if(sum >= INTMAX - cur) {
			return binarySearch(l, mid - 1, exp);
		}
		sum += cur;
		if(i != exp && cur >= INTMAX/mid) {
			return binarySearch(l, mid - 1, exp);
		}
		else cur *= mid;
	}
	if(sum == n) return 1;
	else if(l >= r) return 0;
	else if(sum > n) return binarySearch(l, mid - 1, exp);
	else if(sum < n) return binarySearch(mid + 1, r, exp);
	// else return 0;
}
void solve() {
	cin >> n;
	if(n <= 6) {
		cout << "NO" << endl;
		return;
	}
	for(int i = 2; i <= 65; i++) {
		int k = sqrt(n) + 1;
		if(binarySearch(2, k, i)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();

}
