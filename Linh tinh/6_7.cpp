#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'o' || s[i] == 'O') {
			s[i] = '*';
		}
	}
	cout << s;
}