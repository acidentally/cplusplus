#include <bits/stdc++.h>
using namespace std;
#define mod 1000007
#define int long long

int cinn() {
	int n; cin >> n; return n;
}

int luu[(int)1e6 + 10] = {};

void fibo(int n) {
	int fib_cur = 1, fib_pre = 1, u;
	
	luu[1] = luu[2] = 1;

	// cout << "1 1 ";

	for(int i = 3; i < n; i++) {
		// cout << fib_cur + fib_pre << ' ';

		//Đẩy fib_cur -> fib tiếp theo
		u = (fib_cur + fib_pre) % mod;
		fib_pre = fib_cur;
		fib_cur = u;
		//vì fib_cur = fib tiếp theo = tổng 2 fib trước
		//fib_cur ban nãy, lấy fib_cur - fib_pre
		

		luu[i] = u % mod;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// int tc; cin >> tc;
	// int temp;
	// fibo(1000001);
	// while(tc--) {
	// 	temp = cinn();
	// 	if(luu[temp] < 0) cout << luu[temp] + mod << endl;
	// 	else cout << luu[temp] << endl;
	// }

	int n; cin >> n;
	fibo(n + 1);
	cout << luu[n] % mod;
}