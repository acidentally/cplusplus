#include <bits/stdc++.h>
using namespace std;

short n = 0; bool x = 0; char c;
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); 
	while(cin >> c) {
		n += x; if(c == '/' || c == 92) x = !x;
	}
	cout << n;
}