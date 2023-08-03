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

string s;
map<char, int> mapp;
map<string, int> mapp2;
set<char> sett;
void khoitao() {
	mapp['I'] = 1;
	mapp['V'] = 5;
	mapp['X'] = 10;
	mapp['L'] = 50;
	mapp['C'] = 100;
	mapp['D'] = 500;
	mapp['M'] = 1000;
	sett.insert('I');
	sett.insert('X');
	sett.insert('C');
	mapp2["IV"] = 4;
	mapp2["IX"] = 9;
	mapp2["XL"] = 40;
	mapp2["XC"] = 90;
	mapp2["CD"] = 400;
	mapp2["CM"] = 900;
}
void solve() {
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(i < s.size() - 1 && sett.count(s[i]) && mapp2[s.substr(i, 2)]) {
			ans += mapp2[s.substr(i, 2)];
			i++;
		}
		else ans += mapp[s[i]];
	}
	cout << ans;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	khoitao();
	solve();
}