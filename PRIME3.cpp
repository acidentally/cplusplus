#include <bits/stdc++.h>
using namespace std;

int const maxn = 2*(int)10e6;

vector < vector <unsigned long long > > pp(11, vector <unsigned long long > ());
vector <bool> isPrime(2*maxn, true);
vector <unsigned long long> primes;
void eratos() {
	isPrime[0] = false; isPrime[1] = false;
	for(int i = 2; i * i <= maxn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j <= maxn; j += i) {
				isPrime[j] = false;
			}
		}
	}
	primes.push_back(0);
	for(int i = 2; i <= maxn; i++) {
		if(isPrime[i] == true) {
			primes.push_back(i);
		}
	}
}


int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	eratos();
	int count1 = 1;
	unsigned long long temp = primes[1] * primes[2] * primes[3];

	for(int i = 3; i <= 10; i++) {
		pp[i].push_back(temp);
		temp *= primes[i + 1];
	} 

	while(pp[3][count1] <= maxn) {
		pp[3].push_back(pp[3][count1] / primes[count1] * primes[count1+3]);
		count1 += 1;
	}

	for(int i = 4; i <= 10; i++) {
		count1 = 2;
		while(pp[i][count1 - 1] <= (unsigned long long)10e18) {
				pp[i].push_back(pp[i-1][count1] * primes[count1 + i - 1]);
				count1 += 1;
		}
	}
	int T; cin >> T;
	unsigned long long N;
	int K;
	for(int i = 1; i <= T; i++) {
		cin >> N >> K;
		cout << pp[K][0];
	}	
	return 0;
}