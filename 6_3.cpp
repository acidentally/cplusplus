#include <bits/stdc++.h>
using namespace std;


int main() {ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for(int i = 1; i < s.size(); i += 2) {
		s.insert(i, "-");
	}
	cout << s;
}