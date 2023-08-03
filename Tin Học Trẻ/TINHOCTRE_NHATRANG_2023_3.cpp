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

int n;
void solve() {
	cin >> n;
	int a[n];
	int full = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		full += a[i];
	}
	int half = full/2;
	int l = 0, r = 0, sum = 0;
	int mini = abs(full - 2 * sum);
	while(r < n) {
		sum += a[r];
		mini = min(mini, abs(full - 2 * sum));
		while(l < r && sum > half) {
			sum -= a[l];
			mini = min(mini, abs(full - 2 * sum));
			l++;
		}
		r++;
	}
	cout << mini;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}