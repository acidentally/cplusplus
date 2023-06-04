#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int cinTemp, res = 0, max;
	priority_queue<int> floors;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		floors.push(cinTemp);
	}

	while(!floors.empty()) {
		max = floors.top();
		for(int i = 0; i < k && !floors.empty(); i++) {
			floors.pop();
		}
		res += (max - 1) * 2;
	}
	cout << res;
}