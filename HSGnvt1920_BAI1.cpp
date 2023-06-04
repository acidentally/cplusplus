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
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if(a + b + c != x + y) {
		cout << "NO";
		return 0;
	} else {
		int sum = a + b + c;
		int amin = min(a, min(b, c));
		int cmax = max(a, max(b, c));
		int bneu = sum - amin - cmax;

		if(amin <= min(x, y) && bneu <= max(x, y)) {
			cout << "YES";
			return 0;
		} else cout << "NO";
	}
}