//https://codeforces.com/problemset/problem/1791/E
#include <bits/stdc++.h>
using namespace std;

int negcount;

void absolute(long long& k) {
	k = (k < 0) ? -k : k;
	negcount += 1;
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long tc; cin >> tc;

	int n;
	long long holder;
	long long min, sum;
	while(tc--) {
		negcount = 0;
		cin >> n;
		min = 200000;
		sum = 0;
		while(n--) {
			cin >> holder;
			if(holder <= 0) absolute(holder);
			sum += holder;

			if(holder < min) min = holder;
		}
		if(negcount % 2 == 1 && min > 0) {
			sum -= 2*min;
		}
		cout << sum;
		if(tc > 0) cout << endl;
	}
}