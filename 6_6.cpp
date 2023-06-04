#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int thuong = 0, hoa = 0, so = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 97) {
			thuong += 1;
		}
		else if(s[i] <= 90 & s[i] >= 65) {
			hoa += 1;
		}
		else so += 1;
	}
	cout << thuong << ' ' << hoa << ' ' << so;
}