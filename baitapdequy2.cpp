#include <bits/stdc++.h>
using namespace std;

int Fib(int n) {
	if(n == 1) return 1;
	else if(n == 2) return 2;
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}
void DF(int i)
int main() {
	int n;
	cin >> n;
	cout << Fib(n);
}
