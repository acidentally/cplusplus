#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int tuso = a * d + b * c, mauso = b * d;
	if(tuso < 0) {
		tuso = -tuso;
		mauso = -mauso;
	}
	if(mauso < 0) {
		tuso = -tuso;
		mauso = -mauso;
	}
	
}