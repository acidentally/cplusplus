#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc; int N;
	stack<int> left, right;
	unsigned long long max;

	for(int j = tc; j >= 1; j--) {

		while(!left.empty()) { left.pop(); }
		while(!right.empty()) { right.pop(); }

		cin >> N; unsigned long long H[N];
		for(int i = 0; i < N; i++) { cin >> H[i]; }

		unsigned long long L[N], R[N];
		L[0] = -1; R[N - 1] = N;
		left.push(0); right.push(N-1);

		for(int i = 1; i < N; i++) {
			while(!left.empty() && H[left.top()] >= H[i]) {
				left.pop();
			}
			L[i] = -1;
			if(!left.empty()) {
				L[i] = left.top();
			}

			while(!right.empty() && H[right.top()] >= H[N - i - 1]) {
				right.pop();
			}
			R[N - i - 1] = N;
			if(!right.empty()) {
				R[N - i - 1] = right.top();
			}

			left.push(i);
			right.push(N - i - 1);

		}

		max = (R[0] - L[0] - 1) * H[0];
		for(int i = 1; i < N; i++) {
			if(max < (R[i] - L[i] - 1) * H[i]) {max = (R[i] - L[i] - 1) * H[i];}
		}
		if(j != tc) {cout << endl;}
		cout << max;
	}
	return 0;
}


