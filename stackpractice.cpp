#include <bits/stdc++.h>
using namespace std;

int main() {
	string a; cin >> a;
	vector <int> numbers;
	int sum = a[0] - '0';
	vector <char> operations;
	for(int i = 1; i < a.length(); i++) {
		if(a[i] - '0' >= 0) {
			numbers.push_back(a[i]);
		}
		else {
			operations.push_back(a[i]);
		}
	}
	while(numbers.size()) {
		if(operations[0] == '+') {
			sum += numbers[0] - '0';
			numbers.erase(numbers.begin());
			operations.erase(operations.begin());
		}
		else if(operations[0] == '-') {
			sum -= numbers[0] - '0';
			numbers.erase(numbers.begin());
			operations.erase(operations.begin());
		}
	}
	cout << sum;
}