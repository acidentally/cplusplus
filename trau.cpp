#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int d, nam;
	for(d = 1; d <= n - 2; d++) {
		for(nam = 1; nam <= n - 2; nam++) {
			if(3 * (m - 5*d - 3*nam) == n - nam - d && (n - nam - d) != 0) {
				cout << d << ' ' << nam << ' ' << n - nam - d;
				return 0;
			}
		}
	}	
	cout << -1;
}