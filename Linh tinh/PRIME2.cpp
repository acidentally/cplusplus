#include <bits/stdc++.h>
using namespace std;

unsigned long long const maxn = 10e18;
int const maxn2 = 10e6;
vector< vector<unsigned long long> > K(11, vector<unsigned long long> ());
int isPrime[2*(int)10e6] = {};

void eratos() {
	isPrime[1] = maxn2; isPrime[0] = maxn2;
	for(int i = 2; i * i <= maxn2; i++) {
		if(isPrime[i] == 0) {
			for(int j = i * i; j <= maxn2; j += i) {
				isPrime[j] = (int)maxn2;
			}
		}
	}
	for(int i = 2; i <= (int)2*10e6; i++) {
		if(isPrime[i] == 0) {isPrime[i] = i;}
	}
	sort(isPrime, isPrime + 2*(int)10e6 + 1);
}

void pp() {
	int i, j;
	int holder = 0;
	unsigned long long count = 1;

	for(i = 3; i <= 10; i++) {
		for(j = 0; j < i; j++) {
			count *= isPrime[j];
		}
		while(K[i][holder] < 10e18) {
			K[i].push_back(count);
			count *= isPrime[j];
			count /= isPrime[j-i];
			j++;
			holder += 1;
		}
	}
}

int main() {
	eratos();
	pp();
	int T, b; cin >> T;
	unsigned long long N;

	for(int i = 1; i <= T; i++) {
		cin >> N >> b;
		cout << lower_bound(K[b].begin(), K[b].begin() + K[b].size(), N);
	}
}