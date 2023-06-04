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
	int tc, d; cin >> tc;
	string s;
	map<int, int> mapp;
	while(tc--) {
		cin >> s;
		d = 0;
		for(int i = 0; i < s.size(); i++) {
			d += (s[i] - '0') << (s.size() - i);
		}
		mapp[d]++;
	}
	int maxi = 0;
	map<int, int>::iterator ptr;
	for(ptr = mapp.begin(); ptr != mapp.end(); ptr++) {
		maxi = max(maxi, ptr -> second);
	}
	cout << maxi;
}