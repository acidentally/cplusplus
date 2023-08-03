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

int sqr(int x) {
	return x * x % 10000;
}

int pow(int x, int n) {
	if(n == 0) return 1;
	else if(n == 1) return x;
	else {
		if(n % 2 == 0) {
			return sqr(pow(x, n / 2));
		} else if(n % 2 == 1) {
			return (x * sqr(pow(x, n / 2))) % 10000;
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int x, n; cin >> x >> n;
	cout << pow(x, n);
}