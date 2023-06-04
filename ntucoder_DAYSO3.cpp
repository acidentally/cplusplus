/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int cinn() {
	int n; cin >> n;
	return n;
}
int sqr(int n, int mod) {
	return (n * n) % mod;
}

int modPow(int base, int power, int mod) {
	if(power == 0) return 1;
	if(power == 1) return base;
	if(power % 2 == 0) {
		return sqr(modPow(base, power/2, mod), mod);
	} else return base * sqr(modPow(base, power/2, mod), mod) % mod;
}

void solve(int k, int n) {
	if(n == 1) {
		cout << 1; return;
	} else if(n <= 3) {
		cout << k; return;
	} else {
		cout << modPow(k, modPow(2, n - 3, 1000000006), 1000000007);
	}	
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	int k, n;
	while(tc--) {
		cin >> k >> n;
		solve(k, n);
		cout << endl;
	}
}

// 1 k k 2k 4k 8k 16k
// 1 2 3 4  5  6  7
// - 0 0 1  2  3  4
// k ^ (2 ^ (n - 3));
// tính 2^(n-3) mod 10^9  + 6
