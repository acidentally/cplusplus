#include <bits/stdc++.h>
using namespace std;

unsigned long maxn = (int) 10e9 - 1;

vector <bool> isPrime(maxn ,true);
vector <unsigned long> primes;

int eratos() {
	int demthu = -1;
	for(unsigned long i = 2; i * i <= maxn; i++) {
		if(isPrime[i] == true) {
			primes.push_back(i);
			demthu += 1;
			for(unsigned long j = i * i; j <= maxn; j += i) {
				isPrime[j] = false;
				}
			}
		}
	return demthu;
}

int main() {
	cout << eratos();
	// int T; cin >> T;

	// while(T--) {
	// 	cin >> N;
	// 	while(h != l) {
	// 		if(primes[mid] < N) {
	// 			l = mid;
	// 			mid = (h + l + 1)/2;
	// 		}
	// 		else if(primes[mid] >= N) {
	// 			h = mid;
	// 			mid = (h + l + 1)/2;
	// 		}
	// 	}
	// 	cout << isPrime[mid] << ' ';
	// }
	return 0;
}