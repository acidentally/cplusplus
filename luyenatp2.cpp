#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long k; cin >> k;
	long long cnt = 9;
	long long digits = 1;
	while(k > cnt * digits) {
		k -= cnt * digits;
		cnt *= 10;	
		digits += 1;
	}
	// cout << cnt << ' ' << digits << ' ' << k;
	string l = to_string(cnt/9 - 1 + ((k % digits == 0) ? k/digits : k/digits + 1)) ;
	cout << l[(k % digits == 0) ? (digits - 1) : (k % digits - 1)];
}