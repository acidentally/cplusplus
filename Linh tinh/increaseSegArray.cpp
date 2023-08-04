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

int n, q, val, u, v;
void solve() {
	cin >> n >> q >> val;
	int Le[n + 10] = {}, Ri[n + 10] = {};
	int a[n + 10] = {};
	while(q--) {
		cin >> u >> v;
		Le[u]++;
		Ri[v]++;
	}
	int cur = 0, maxi = 0;
	for(int i = 1; i <= n; i++) {
		cur += Le[i] - Ri[i - 1];
		maxi = max(maxi, cur);
	}
	cout << maxi * val;

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}