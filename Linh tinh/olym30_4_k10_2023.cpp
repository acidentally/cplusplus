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
	int t, n, mini = 1e18, maxi = 0, maxLen = 0; 
	int cinTemp;
	cin >> t >> n;
	deque<int> xet;
	fr(i,0,n) {
		cin >> cinTemp;
		xet.push_back(cinTemp);
		maxi = max(maxi, cinTemp);
		mini = min(mini, cinTemp);

		if(xet.size() <= 1) {
			continue;
		} else {
			while(!xet.empty() && maxi - mini > t) {
				if(mini == xet.front()) {
					mini = 1e18;
				}
				if(maxi == xet.front()) {
					maxi = 0;
				}
				xet.pop_front();
				mini = min(mini, xet.front());
				maxi = max(maxi, xet.front());
			}
			maxLen = max(maxLen, (int)xet.size());
		}
	}
	cout << maxLen;
}