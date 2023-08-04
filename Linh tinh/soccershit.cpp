#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if(a + b < n) {
		cout << n-a-b << endl;
		while(a--) {
			cout << "1:0" << endl;
			n--;
		}
		while(b--) {
			cout << "0:1" << endl;
			n--;
		}
		while(n--) {
			cout << "0:0";
			if(n != 1) {cout << endl;}
		}
	}
	else if(a + b >= n) {
		cout << 0 << endl;
		if(a < n && b < n) {
			while(a--) {
				cout << "1:0" << endl;
				n--;
			}
			while(n-2) {
				cout << "0:1" << endl;
				n--; b--;
			}
			cout << "0:" << b;
		}

		else if(a >= n || b >= n) {
			if(a >= b) {
				cout << "0:" << b << endl;
				while(n-2) {
					cout << "1:0" << endl;
					a--; n--;
				}
				cout << a << ":0";
			} 
			else if(a < b) {
				cout << a << ":0" << endl;
				while(n-2) {
					cout << "0:1" << endl;
					b--; n--;
				}
				cout << "0:" << b;
			}
		}
	}
}



