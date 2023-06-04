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

void solvemax(int n) {
	string s = "";
	s = ((n % 2) ? '7' + s : s);
	if(n % 2) n -= 3;
	for(int i = 0; i < n / 2; i++) {
		s = s + '1';
	}
	cout << s << endl;
}
char d[7] = {'1', '1', '1', '7', '4', '2', '0'};
void solvemin(int n) {
	
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	if(n == 2) {
		cout << 1 << endl << 1;
		return 0;
	}
	if(n == 3) {
		cout << 7 << endl << 7;
		return 0;
	}
	if(n == 4) {
		cout << 4 << endl << 11;
		return 0;
	}
	else {
		solvemax(n);
		solvemin(n);
	}
}