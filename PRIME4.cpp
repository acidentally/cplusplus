#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	long long b[n], c[n];

	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}

	long long test;
	long long min = b[0] + c[0];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			test = (b[i] + c[j] > 0) ? (b[i] + c[j]) : (-b[i] - c[j]);
			if(test < min) {min = test;}
		}
	}
	cout << min;
}