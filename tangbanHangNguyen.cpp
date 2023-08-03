#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n], ans = 10000000;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			ans = min(ans, a[i] + a[j]);
		}
	}
	cout << ans;
}