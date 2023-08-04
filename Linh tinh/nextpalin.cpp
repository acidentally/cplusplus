//https://www.spoj.com/problems/PALIN/
#include <bits/stdc++.h>
using namespace std;

void NumberStringSum(string& numbers, int pivot) {
	while(numbers[pivot] - '9' == 0 && pivot >= 0) {
		numbers[pivot--] = '0';
	}
	if(pivot != -1) {
		numbers[pivot] += 1;
	}
	if(pivot == -1) {
		numbers = '1' + numbers;
	}
}
void nextPalin(string number) {
	int halfPivot = number.length()/2 - 1;
	int i;
	bool ogPrint = true;
	for(i = halfPivot; i >= 0; i--) {
		if(number[i] < number[number.length() - i - 1]) {
			ogPrint = false;
			break;
		}
		if(number[i] > number[number.length() - i - 1]) {
 			break;
		}
	}

	if(ogPrint == false || i == -1) {
		if(number.length() % 2) {
			NumberStringSum(number, halfPivot + 1);
		}
		else NumberStringSum(number, halfPivot);
	}
	halfPivot = number.length()/2 - 1;
	for(int i = 0; i <= halfPivot; i++) {
		cout << number[i];
	}
	if(number.length() % 2) {
		cout << number[halfPivot + 1];
	}
	for(int i = halfPivot; i >= 0; i--) {
		cout << number[i];
	}

}

int main() {
	int tc; cin >> tc;
	string number;
	int i;
	for(i = 1; i <= tc; i++) {
		cin >> number;
		nextPalin(number);
		if(i < tc) cout << '\n';
	}
}

