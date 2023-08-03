#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, k, count;
	while(tc--) {
		cin >> n >> k;
		count = 1;
		while(k > 3) {
			cout << 1 << ' ';	
			k--; n--;
		}
		while(n % 2 == 0 && n > 3) {
			count *= 2;
			n /= 2;
		}
		cout << count << ' ' << count*(n-1)/2 << ' ' << count*(n-1)/2;
		if(tc > 0) cout << endl;
	}
}