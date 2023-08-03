#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if((s[i] > 90 && s[i] < 97) || (s[i] > 122) || (s[i] < 65)) {
			s.erase(i, 1);
			i--;
		}
	}
	cout << s;
	// cout << (int) 'a' << ' ' << (int) 'z' << endl;
	// cout << (int) 'A' << ' ' << (int) 'Z';
}