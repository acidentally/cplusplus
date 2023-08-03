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

int n, a, b, x;
void solve() {
	cin >> n >> a >> b;
	int k = n;
	int x1 = 0, x2 = 0;
	while(k--) {
		cin >> x;
		if(x & 1) x1++;
		else x2++;
	}
	cout << n * min(a, b) + x2 * max(a, b);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}