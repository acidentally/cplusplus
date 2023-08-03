#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int cinTemp;
	vector<int> numbers;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		numbers.push_back(cinTemp);
	}
	int sum = 0;
	sort(numbers.begin(), numbers.end());
	for(int i = 0; i < n; i++) {
		if(i == 0) sum += abs(numbers[0] - numbers[1]);
		else if(i == n - 1) sum += abs(numbers[n - 1] - numbers[n - 2]);
		else {
			sum += min(abs(numbers[i] - numbers[i - 1]), abs(numbers[i] - numbers[i + 1]));
		}
	}
	cout << sum;
}

