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
int sqrsum(int k) {
	return k * (k + 1) * (2 * k + 1) / 6;
}
int count(int a, int b) {
	if(a < b) return a + n - b;
	else return a - b;
}

void solve() {
	cin >> n;
	int a[n + 10] = {}, pre[n + 10] = {};
	cin >> a[0]; pre[0] = a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		if(a[i] == 0) cnt++;
	}
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] == 0) pre[i]++;
	}

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}