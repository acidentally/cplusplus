#include <bits/stdc++.h>
using namespace std;
bool solve(string s) {
	int i = 0;
	while(i < s.size() / 2) {
		if(s[i] != s[s.size() - 1 - i]) return 0;
		i++;
	}
	return 1;
}

signed main() {
	string s; cin >> s; cout << solve(s);
}