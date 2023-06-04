#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ahaha; cin >> n;
	int k = n;
	deque<int> shit;
	while(k--) {
		cin >> ahaha;
		shit.push_back(ahaha);
	}

	vector<char> output;
	int length = 0;
	int number;

	for(int i = 1; i <= n; i++) {
		number = shit.front();
		shit.pop_front();
		if(number > shit.front()) {
			swap(number, shit.front());
			output.push_back('S');
			length += 1;
			i = 0;
		}
		shit.push_back(number);
		output.push_back('P');
		length += 1;
	}
	for(int i = 0; i < length - n; i++) {
		cout << output[i];
	}
}
