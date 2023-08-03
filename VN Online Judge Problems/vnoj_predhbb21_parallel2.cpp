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

int n, u, v;
void solve() {
	cin >> n;
	while(n--) {
		cin >> u >> v;
		if(u >= 3 || v >= 3) {
			cout << "No" << endl;
		}
		else if(u + v <= 3 && (u <= 2 || v <= 2)) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}