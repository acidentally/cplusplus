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
	string s; cin >> s;
	int curIdx = 0;
	int ans = 1;
	int curLen;
	for(int i = 0; i < s.size() - 1; i++) {
		if(s[i] - 48 == 9 - (s[i + 1] - 48)) {
			// cout << i << endl;
			curIdx = i;
			while(i < s.size() - 1 && s[i] - 48 == 9 - (s[i + 1] - 48)) {
				i++;
			}
			curLen = i - curIdx + 1;
			// cout << curLen << ' ';
			if(curLen % 2 == 1) ans *= (curLen - 1)/2 + 1;
		}
	}
	cout << ans;
}