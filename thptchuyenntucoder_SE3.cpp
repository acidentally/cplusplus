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

int n, k;
void solve() {
	cin >> n >> k;
	n--;
	int ans = n / 2 * 3 + (n % 2) + 1;
	cout << ans % k << endl;
	cout << ((ans % k) - 1) * ((ans % k) + 1) % k << endl;

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}