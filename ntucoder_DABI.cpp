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

void solve(int x) {
	string s = "";
	int d = x;
	while(d) {
		s = (char)(d % 10 + '0') + s;
		d /= 10;
	}
	int temp = 0;
	for(int i = 0; i < s.size(); i++) {
		temp += s[i] - '0';
	}
	if(x % temp) cout << false;
	else cout << true;
	return;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int x; cin >> x;
	solve(x);
}