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
int const INF = 1e9;
int n, k;
void solve() {
	cin >> n >> k;
	int a[n + 10] = {}, b[n + 10] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] * k;
	}	
	if(n == 1) {
		cout << max(a[1], max(a[1] * k, 0ll));
		return;
	}
	if(k != 0) {
		int r = 1;
		int mainL = 0, mainR = 0;
		int ans = -INF, cur = 0;
		for(int i = 1; i <= n; i++) {
			cur += b[i];
			if(ans < cur) {
				ans = cur;
				mainL = r;
				mainR = i;
			}
			if(cur <= 0) {
				cur = 0;
				r = i + 1;
			}
		}
		for(int i = mainL; i <= mainR; i++) {
			a[i] *= k;
		}
	}
	int curr = 0, maxi = -INF;
	for(int i = 1; i <= n; i++) {
		curr = max(a[i], curr + a[i]);
		maxi = max(maxi, curr);
	}
	if(k == 0) {
		cout << max(maxi, 0ll);
		return;
	}
	cout << maxi;
}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}