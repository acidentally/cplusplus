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

int n, m;
char a[101][101], x;
void solve() {
	cin >> n >> m;
	int ans = 0, half = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> x;
			if(x == '/' || (int)x == 92) {
				half += 1;
				while(1) {
					cin >> x;
					if(x != 92 && x != '/') {
						ans++;
						j++;
					}
					else {
						j++;
						break;
					}
				}
			}
		}
	}
	cout << ans + half;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}