#include <bits/stdc++.h>
using namespace std;
int cnt = 1, eratosRestricted;
int prines[10001];
void primes(int a, int b) {
	vector<bool> isPrime(b - a + 1, true);
	for(int i = 2; i * i <= b; i++) {
		for(int j = max(i * i, (a + i - 1) / i * i); j <= b; j += i) {
			isPrime[j - a] = false;
		}
	}
	if(1 - a >= 0) {
		isPrime[1 - a] = false;
	}

	for(int i = a; i <= b && cnt <= eratosRestricted; i++) {
		if(isPrime[i - a] && cnt <= eratosRestricted) {
			prines[cnt] = i;
			cnt++;
		}
	}
}



int main() {
	int l = 0, r = 10000;
	cin >> eratosRestricted;
	eratosRestricted++;
	while(cnt <= eratosRestricted) {
		primes(l, r);
		l = r + 1;
		r += 10000;
	}
	for(int i = 2; i <= eratosRestricted; i++) {
		cout << prines[i] << endl;
	}
}


