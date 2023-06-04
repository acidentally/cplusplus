#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int n;
	while(t--) {
		cin >> n;
		int numbers[n], sum = 0;
		deque <int> pivot; bool YesOrNo = true;
		for(int i = 0; i < n; i++) {
			cin >> numbers[i];

			if(i == 1 && numbers[i] == numbers[i - 1]) {
				cout << "NO";
				YesOrNo = false;
				break;
			}
			else if(numbers[i] == sum) {
				pivot.push_back(i - 1);
			}
			sum += numbers[i];
		}
		if(YesOrNo) {
			for(int i = 0; i < n; i++) {
				if(i == pivot.front()) {
					cout << numbers[i + 1] << ' ' << numbers[i++] << ' ';
					pivot.pop_front();
					continue;
				}
				else {
					cout << numbers[i] << ' ';
				}
			}

		}
	}	
}