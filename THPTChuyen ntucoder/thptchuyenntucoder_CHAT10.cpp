#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
int cinn() {
	int n; cin >> n;
	return n;
}
int n, a[(int)1e5 + 10];
int mid;
void solve(int k) {
	int l = 0, r = n - 1;
	while(l < r) {
		mid = (l + r)/2;
		if(k >= a[mid] && k <= a[mid + 1]) {
			cout << min(abs(a[mid] - k), abs(a[mid + 1] - k)) << endl;
			return;
		} else if(a[mid] <= k) {
			l = mid + 1;
		} else r = mid;
	}
	cout << min(abs(a[mid] - k), abs(a[mid + 1] - k)) << endl;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int tc; cin >> tc;
	while(tc--) {
		solve(cinn());
	}
}