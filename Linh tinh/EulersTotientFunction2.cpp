#include <bits/stdc++.h>
using namespace std;

int euler(int n) {
	int count = n;
	vector<int> minPrime(n + 1, 0);
	for(int i = 2; i * i <= n; i++) {
		if(minPrime[i] == 0) {
			for(int j = i * i; j <= n; j += i) {
				if(minPrime[j] == 0) {
					minPrime[j] = i;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(minPrime[i] == 0) {
			minPrime[i] = i;
		}
	}

	vector<int> primes(count + 1);
	int temp;

	while(n != 1) {
		temp = minPrime[n]; 
		primes.push_back(temp);
		while(minPrime[n] == temp) {
			n /= minPrime[n];
		}
	}
	
	for(int i = 0; i <= primes.size() - 1; i++) {
		count *= primes[i] - 1;
		count /= primes[i];
	}
	return count;
}

int main() {
	int t; cin >> t;
	int n[t+1];
	for(int i = 1; i <= t; i++) {
		cin >> n[i];
		cout << euler(n[i]);
	}
	return 0;
}