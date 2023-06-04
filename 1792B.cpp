#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int a1, a2, a3, a4;
	int res, minSas;
	while(tc--) {
		res = 0, minSas = 0;
		cin >> a1 >> a2 >> a3 >> a4;
		minSas += a1;
		res += a1;
		if(res == 0) {
			cout << 1 << endl;
			continue;
		}
		else if(res >= 1) {
			res += 2*min(a2,a3) + ((minSas + 1 >= (max(a2, a3) - min(a2, a3) + a4)) ? (max(a2, a3) - min(a2, a3) + a4) : minSas + 1); 
		}
		cout << res << endl;
	}
}	