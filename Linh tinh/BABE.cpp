//http://ntucoder.net/Problem/Details/1173
#include <bits/stdc++.h>
using namespace std;
int const maxn = (int)10e7 + 9;

vector<bool> isPrime(maxn, true);
vector<int> primes;

void eratos() {
	isPrime[2] = true;
	for(int i = 2; i * i <= maxn; i++) {
		if(isPrime[i] == true) {
			for(int j = i * i; j <= maxn; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i <= maxn; i++) {
		if(isPrime[i]) primes.push_back(i);
	}
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	eratos();
	int n; cin >> n;
	cout << primes[n - 1];
}	