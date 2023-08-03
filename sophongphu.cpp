#include <bits/stdc++.h>
using namespace std;

bool pp(int a) {	
	int res = 0;
	for(int i = 1; i * i <= a; ++i) {
		if(a % i == 0) {
			res += i + a/i;
		}
		if(i * i == a) {
			res -= i;
		}		
	}
	
	if(res > 2*a) {
		cout << a << ' ';
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int L, R, count = 0;
	cin >> L >> R;
	
	for(int k = L; k <= R; k++) {
		if(pp(k)) {
			count += 1;
		}
	}
	cout << '\n' << count;
}