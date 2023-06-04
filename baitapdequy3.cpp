#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(a == 1 || b == 1) return 1;
	else if(a == 0 || b == 0) return (a == 0) ? b : a;
	else {
		if(a > b) return gcd(b , a%b);
		else return gcd(a, b%a);
	}
}

int main() {
	int a, b; cin >> a >> b;
	cout << gcd(a, b);
}