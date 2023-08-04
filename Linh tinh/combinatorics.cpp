#include <bits/stdc++.h>
using namespace std;

int lmao(int k, int n) {
	long result = 1;
	if(k <= n/2) {
		k = n - k;
	}
	for(int i = k + 1; i <= n; i++) {
		result *= i;
	}
	for(int i = 1; i <= n - k; i++) {
		result /= i;
	}
	return result;
}

int main() {
	int n, k;
	cin >> k >> n;
	cout << lmao(k, n);
}