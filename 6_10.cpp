#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int i;
	for(i = 0; i <= (s.length() - 1)/2; i++) {
		if(s[i] != s[s.length() - 1 - i]) {
			break;
		}
	}
	if(i < (s.length() - 1)/2 + 1) {
		cout << "NO"; 
	}
	else {
		cout << "YES";
	}
}