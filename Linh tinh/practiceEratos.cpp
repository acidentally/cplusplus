#include <bits/stdc++.h>
using namespace std;

void segSieve(int a, int b) {
	vector<bool> primes(b - a + 1, true);
	for(int i = 2; i * i <= b; i++) {
			for(int j = max(i * i, (a + i - 1) / i * i); j <= b; j += i) {
				primes[j-a] = false;
			}
	}
	if(1 >= a) {
		primes[1 - a] = false;
	}
	int res = 0;
	for(int i = a; i <= b; i++) {
		if(primes[i - a] == true) {
			// cout << i << '\n';	
			// cout << i << ' ';
			res++;
		}
	}
	cout << res << '\n';
}

int main() {
	int a, b; cin >> a >> b; segSieve(a, b);
}