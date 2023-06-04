#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int g, c;
	if(m % 2 == 1 || 2*n - m/2 < 0 || m/2 - n < 0) {cout << -1; return 0;}
	cout << 2*n - m /2 << ' ' << m/2 - n;
}