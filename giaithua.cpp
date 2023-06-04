#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int giaithua = 1, S = 0;
	for(int i = 1; i <= N; i++) {
		giaithua *= i;
		S = (i % 2) ? S - giaithua : S + giaithua;
	}
	cout << S;
}
// 1 + 2 + 6 + 24 + 120