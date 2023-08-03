#include <bits/stdc++.h>
using namespace std;

int const maxn = 10e6;
unsigned long long isPrime[maxn + 1] = {};
unsigned long long N[16], sum;

void eratos() {
	isPrime[1] = maxn; isPrime[0] = maxn;
	for(int i = 2; i * i <= maxn; i++) {
		if(isPrime[i] == 0) {
			for(int j = i * i; j <= maxn; j += i) {
				isPrime[j] = maxn;
			}
		}
	}
	for(int i = 2; i <= (int)10e6; i++) {
		if(isPrime[i] == 0) {isPrime[i] = i;}
	}
	sort(isPrime, isPrime + (int)10e6);
}


int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	eratos();
	int T; cin >> T;
	int K[T+1]; 
	int count, o, j;
	for(o = 1; o <= T; o++) {
		sum = 1;
		cin >> N[o] >> K[o]; count = K[o];
		for(j = 0; j < K[o]; j++) {
			sum *= isPrime[j];
		}
		if(sum > N[o]) {cout << -1 << '\n'; continue;}
		while(sum <= N[o]) {
			sum = sum * isPrime[count] / isPrime[count - K[o]];
			count += 1;
		}
		cout << sum * isPrime[count - K[o] - 1] / isPrime[count - 1] << '\n';
	}
	return 0;
}