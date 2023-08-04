#include <bits/stdc++.h>
using namespace std;
string s, s1 = "";
void DFS(int i) {
	if(i == s.size() + 1) {
		cout << s1;
	}
	else {
		s1 = s1 + s[s.size() - i];
		DFS(i + 1);
	}
}

int main() {
	cin >> s;
	// for(int i = s.size() - 1; i >= 0; i--) {
	// 	cout << s[i];
	// }

	// string s1 = "";
	// for(int i = 0; i <= s.size() - 1; i++) {
	// 	s1 = s[i] + s1;
	// }	
	// cout << s1;
	DFS(1);
}