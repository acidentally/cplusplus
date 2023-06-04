#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unsigned long long sum = 0, temp;
	int N; cin >> N;
	while(N--) {
		cin >> temp;
		sum += temp;
	}
	cout << sum;
}