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

int const modn = (int)1e9 + 7;
int n, ans;
int x, y;
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if(n == 1 || n == 2) {
		cout << n - 1;
		return 0;
	}
	if(n == 3) {
		cout << 2;
		return 0;
	} 
	x = 1; y = 2;
	for(int i = 4; i <= n; i++) {
		ans = ((i - 1) % modn) * (x % modn + y % modn) % modn;
		x = y; 
		y = ans;
		// cout << i << ": " << ans << endl;
	}
	cout << ans;
}