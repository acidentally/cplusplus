#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	string s1;
	for(int i = s.length() - 1; i >= 0; i--) {
		s1 += s[i];
	}
	cout << s1;
}