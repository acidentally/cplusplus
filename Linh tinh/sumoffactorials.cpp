#include <bits/stdc++.h>
using namespace std;

unsigned long fac(unsigned long n) {
	unsigned long sum = 1;
	for(int i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}

int main() {
	unsigned long n;
	cin >> n;
	unsigned long result = 0;
	for (unsigned long i = 1; i <= n; i++) {
		result += fac(i);
	}
	cout << result;
}