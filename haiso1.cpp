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

int attempt(int idx, bool restricted, int cnt) {
	if(idx < 0) return 1;

}

void solve(int n) {
	string s = "";
	while(n) {
		s = s + char(n % 2 + 48);
		n >>= 1;
	}	
	cout << attempt(s.size() , 0, 0);
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	int x;

	while(tc--) {
		cin >> x;
		solve(x);
		cout << endl;
	}
}