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


map<int, int> mapp;

void solve(string& s) {
	for(int i = 0; i < s.size(); i++) {
		if(65 <= s[i] && s[i] <= 90) {
			mapp[s[i] - 65]++;
		} else if(s[i] >= 97 && s[i] <= 122) mapp[s[i] - 65]++;
	}
	for(auto const& ptr : mapp) {
		cout << char(ptr.fi + 65) << ' ' << (int)ptr.se << ' ';
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	string temp; getline(cin, temp);
	string aha;
	getline(cin, aha);
	solve(aha);
}