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
	int n; cin >> n;
	multiset<int> dexuat, sotai;

	for(int i = 0; i < n; i++) {
		dexuat.insert(cinn());
	}
	for(int i = 0; i < n; i++) {
		sotai.insert(cinn());
	}
	// sotai.insert(1e18); dexuat.insert(1e18);
	// cout << *sotai.begin();
	int ans = 0;
	multiset<int>::iterator dx = dexuat.begin(), st = sotai.begin();
	// cout << *st << endl;

	while(dx != dexuat.end() && st != sotai.end()) {
		// cout << *st << ' ' << *dx << endl;
		if(*st <= *dx) st++;
		else {
			ans++;
			st++;
			dx++;
		}
	}
	cout << ans;	
}