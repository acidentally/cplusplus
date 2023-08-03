#include <bits/stdc++.h>
using namespace std;

//Tính nCk

int com(int k, int n) { 
	int res = 1;
	int u = (k >= n - k) ? k : n - k;
	int v = n - u;
	for(int i = u+1; i <= n; i++) {
		res *= i;
	}
	for(int i = v; i >= 1; i--) {
		res /= i;
	}
	return res;
}

int main() {
	int n, d;
	cin >> n >> d;
	
}



