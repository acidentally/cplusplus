#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int len; 
	string a;
	int dem;
	while(t--) {
		cin >> len;
		cin >> a;
		dem = a[0] - '0';
		for(int i = 1; i < len; i++) {
			if(dem == 0) {dem += a[i] - '0'; cout << "+";}
			else if(dem == 1) {dem -= a[i] - '0'; cout << "-";}
		}
		cout << '\n';
	}
}