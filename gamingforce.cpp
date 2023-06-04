#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, cnt, temp;
	while(tc--) {
		cnt = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			if(temp == 1) cnt++;
		}
		cout << n - cnt/2 << '\n';
	}
}