/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int __int64
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

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, t; cin >> n >> t;

	switch(n % 4) {
	case 0 : cout << t + (n/4) * 2; break;
	case 1 : cout << t - 1; break;
	case 2 : cout << t - (n/4 + 1) * 2; break;
	case 3 : cout << t; break;
	}
}

// -1 
// -2
// 0
// 2

// -1
// -4
// 0 
// 4

// -1
// -6
// 0
// 6

// -1
// -8
// 0
// 8
