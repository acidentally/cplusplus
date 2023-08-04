#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	bool dangtu = false;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != '.' && dangtu == false)  {
			dangtu = true;
			cnt++;
		}
		if(s[i] == '.' && s[i - 1] != '.') {
			dangtu = false;
		}
	}
	cout << cnt;	
}