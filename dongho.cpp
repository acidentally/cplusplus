#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, p, s; cin >> h >> p >> s;
	int count = 3600*h + 60*p + s + 1;
	h = count / 3600; 
	count -= 3600*h; 
	p = count / 60;
	count -= 60*p;
	s = count;
	// if(s == 59) {
	// 	s = -1;
	// 	if(p == 59) {
	// 		p = 0;
	// 		if(h == 23) {
	// 			h = 0;
	// 		} else h += 1;
	// 	}	
	// 	else p += 1;
	// } 
	if(h == 24) cout << "0 0 0";
	else {
		cout << h << ' ' << p << ' ' << s;
	}
}