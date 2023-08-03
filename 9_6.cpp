#include <bits/stdc++.h>
using namespace std;

int n;

void primeFactor(int i) {
	if(i > n) {return;}
	else {
		if(n % i == 0) {
			n /= i; cout << i << ' ';
			primeFactor(i);
		}
		primeFactor(i + 1);
	}
}

int main() {
	cin >> n; 
	primeFactor(2);
}