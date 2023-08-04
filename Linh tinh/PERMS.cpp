//http://ntucoder.net/Problem/Details/111
#include <bits/stdc++.h>
using namespace std;

int n;
int perms[10];
bool check[10] = {};

void fac(int k) {
	int res = k;
	while(k--) {
		res *= (k) ? k : 1;
	}
	cout << res << endl;
}

void backTracking(int i) {
	if(i > n) {
		for(int j = 1; j <= n; j++) {
			cout << perms[j];
		}
		cout << endl;
	}
	else {
		for(int j = 1; j <= n; j++) {
			if(check[j] == false) {
				check[j] = true;
				perms[i] = j;
				backTracking(i + 1);
				check[j] = false;
			}
		}
	}

}

int main() {
	cin >> n;
	fac(n);
	backTracking(1);
}


//1 2 3 4 5