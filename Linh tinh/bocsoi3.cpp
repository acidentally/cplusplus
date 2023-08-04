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
	if(n == 0) cout << "NO";
	else {
		while(n) {
			if(n & 1) {
				n >>= 1;
			}
			else {
				cout << "YES";
				return;
			}
		}
		cout << "NO";
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}