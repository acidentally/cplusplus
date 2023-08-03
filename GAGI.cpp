#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	int cnt = 0;
	cin >> a >> b;
	while(b > a) {
		a *= 2; 
		cnt++;
	}
	if(a == b) {
		cout << cnt;
	}
	else {
		cout << cnt - 1;
	}

}