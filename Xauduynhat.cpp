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
	string s; getline(cin, s);
	int l = s.size() - 1, r = s.size() - 1;
	int maxLen = 0;
	bool checkChar[256] = {};
	while(l != -1) {
		if(!checkChar[s[l]]) {
			checkChar[s[l]] = true;
		} else {
			maxLen = max(maxLen, r - l);
			while(s[r] != s[l]) {
				checkChar[s[r]] = false;
				r--;
			}
			r--;
		}
		l--;
	} 
	cout << max(maxLen, r - l);
}