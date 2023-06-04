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
vi fib;
void start() {
	// fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);
	for(int i = 2; i <= 45; i++) {
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}
}

int cinn() {
	int n; cin >> n;
	return n;
}

map<pair<int, int>, int> mapp;

int solve(int fibo, int len) {
	if(mapp[{fibo, len}] != 0) return mapp[{fibo, len}];
	else {
		if(fibo == 0) return 1;
		else if(fibo == 1 || len == 0) return 0;
		else if (len <= fib[fibo - 2]) {
			mapp[{fibo - 2, len}] = solve(fibo - 2, len);
			return mapp[{fibo - 2, len}];
		} else if(len > fib[fibo - 2]) {
			mapp[{fibo - 2, fib[fibo - 2]}] = solve(fibo - 2, fib[fibo - 2]);
			mapp[{fibo - 1, len - fib[fibo - 2]}] = solve(fibo - 1 ,len - fib[fibo - 2]);
			return mapp[{fibo - 2, fib[fibo - 2]}] + mapp[{fibo - 1, len - fib[fibo - 2]}];
		}		
	}
}

	
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	start();
	int tc; cin >> tc;
	int fibo, len;
	while(tc--) {
		cin >> fibo >> len;
		// cout << fibo << ' ' << len << ' ';
		cout << solve(fibo, len) << endl;
	}
}