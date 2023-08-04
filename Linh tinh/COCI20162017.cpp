#include <bits/stdc++.h>
using namespace std;

long sod(int a) {
	long res = 1;
	if(a < 2) return a - 1;
	for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			res += i + a/i;
		}
		if(i * i == a) res -= i;
	}
	return res;
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long sum = 0;
	int A, B; cin >> A >> B;
	for(int i = A; i <= B; i++) {
		sum += (sod(i) > i) ? (sod(i) - i) : (i - sod(i));
	}
	cout << sum;
}