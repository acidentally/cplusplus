#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	long long K, A[N]; cin >> K;
	set<long long> remainder;

	for(int i = 0; i < N; i++) {
		cin >> A[i];
		remainder.insert(A[i] % K);
	}

	cout << remainder.size();
}