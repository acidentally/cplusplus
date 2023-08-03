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
vi a;

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a.push_back(x);
	}
	int sum1 = 0, sum2 = 0;
	for(int i = 1; i < n; i++) {
		if(i % 2 == 1) {
			sum1 += a[i] - 1;
			sum2 += a[i - 1] - 1;
		}
		else {
			sum1 += a[i - 1] - 1;
			sum2 += a[i] - 1;
		}
	}
	cout << max(sum1, sum2);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}