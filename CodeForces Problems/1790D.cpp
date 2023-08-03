#include <bits/stdc++.h>
using namespace std;

#define int long long
int const maxn = (int)1e9;

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, cinTemp;
	int sum, negCount, min;
	bool check;
	while(tc--) {
		cin >> n;
		sum = 0; negCount = 0;	
		min = maxn;
		check = false;
		for(int i = 0 ; i < n; i++) {
			cin >> cinTemp;
			sum += abs(cinTemp);
			if(abs(cinTemp) < min) min = abs(cinTemp);
			if(cinTemp < 0) negCount++;
			if(cinTemp == 0) check = true;
		}
		if(check == true || negCount % 2 == 0) {
			cout << sum;
		} else {
			cout << sum - 2*min;
		}
		cout << '\n';
		// cout << min;
	}
}