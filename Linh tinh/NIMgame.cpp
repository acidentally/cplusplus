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
void solve() {
	cin >> n;
	int s = 0, a[n + 10] = {};
	int maxi = 0, bigIdx = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > maxi) {
			bigIdx = i;
			maxi = a[i];
		}
		s = s ^ a[i];
	}
	if(s == 0) {
		cout << "Thua boc 1 vien dong thu " << bigIdx;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] - (a[i] ^ s) > 0) {
			cout << "Thang boc " << a[i] - (a[i] ^ s) << " vien dong thu " << i;
			return;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}