#include <bits/stdc++.h>
using namespace std;

int const maxn = 100000009;
int prime[maxn - 7] = {0}; 


vector<bool> isPrime(maxn, true);

void allprimes() {
	isPrime[1] = false;
	for(int i = 2; i * i <= maxn; i++) {
		if(isPrime[i] == true) {
			for(int j = i * i; j <= maxn; j += i) {
				isPrime[j] = false;
			}
		}
	}
}


int main() {
	ios_base:: sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	allprimes();
	prime[2] = 1;
	float holder = 1; int x;

	for(int i = 3; i <= maxn - 8; i++) {
		if(isPrime[i] == true) {holder += 1;}
		prime[i] = holder;
	}
	while(cin >> x && x) {
		float u = x;
		if(x == 0) return 0;
		cout << fixed << setprecision(1) << abs(1 - u/prime[x]/log(x))*100 << endl;
	}
}