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

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	string x, y; cin >> x >> y;
	int idx = 0, a = 0, b = 0;
	while(x[idx] != '.' && idx < x.size()) {
		a = a * 10 + x[idx] - 48;
		idx++;
	}
	if(idx != x.size()) a += 1;
	idx = 0;
	while(y[idx] != '.' && idx < y.size()) {
		b = b * 10 + y[idx] -48;
		idx++;
	}
	cout << (b - a + 1) * (b + a) / 2;
}