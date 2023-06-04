#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	int n[t + 1], res;
	for(int i = 1; i <= t; i++) {
		cin >> n[i];
		res = n[i];
		for(int j = 2; j * j <= n[i]; j++) {
			if(n[i] % j == 0) {
				res *= j - 1;
				res /= j;
				while(n[i] % j == 0) {
					n[i] /= j;
				}
			}
		}
		if(n[i] != 1) {
			res -= res/n[i];
		}
		cout << res << '\n';
	}	
	return 0;
}