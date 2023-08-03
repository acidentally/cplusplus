#include <bits/stdc++.h>
using namespace std;

const int A = 10000009;
int F[A];

void per() {	
	for(int i = 1; i <= A; i++) {
		for(int j = i; j <= A; j += i) {
			F[j] += i;
		}
	}
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	per();
	long A, B, sum = 0;
	cin >> A >> B;
	for(long i = A; i <= B; i++) {
		sum += abs(F[i] - 2*i);
	}
	cout << sum;
}