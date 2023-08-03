#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; getline(cin, s);
	while(s[0] == ' ') {
		s.erase(0, 1);
	}
	while(s[s.size() - 1] == ' ') {
		s.erase(s.size() - 1, 1);
	}
	s[0] = (s[0] >= 97) ? s[0] - 32 : s[0];
	for(int i = 1; i < s.size(); i++) {
		if(s[i - 1] != ' ') {
			if(s[i] == ' ') continue;
			else {
				s[i] = (s[i] <= 90) ? s[i] + 32 : s[i];
			}
		}
		if(s[i - 1] == ' ' && s[i] == ' ') {
			s.erase(i, 1);
			i--;
		}
		else if(s[i - 1] == ' ' && s[i] != ' ') {
			s[i] = (s[i] >= 97) ? s[i] - 32 : s[i];
		}
	}
	cout << s << endl;
	cout << (char)97;
	// cout << (int) 'a' << ' ' << (int) 'z' << endl;
	// cout << (int) 'A' << ' ' << (int) 'Z';
}