#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while(a || b) {
		a %= b;
		if(a) {
			b %= a;
		}
	}
	int x = (a == 0) ? b : a;
	return x; 
}

int res(int n) {
	int a, b;
	int min = n - 1;
	for(int i = 2; i <= n/3 + 1; i++) {
		if (min > i*(n - i)/gcd(i, n)) {
			min = i*(n - i)/gcd(i, n);
			a = i; 
			b = n - i;
		}
	}
	cout << a << ' ';
	return b;
}

int main() {
	int t;
	cin >> t;
	int cock[t + 1];
	for (int i = 1; i <= t; i++) {
		cin >> cock[i];
	}

	for(int i = 1; i <= t; i++) {
		cout << res(cock[i]) << '\n';
	}
}