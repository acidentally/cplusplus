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
	int n, maxi, cinTemp, coutIdx; cin >> n;
	vi a, dp, trace;
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
		dp.push_back(1);
		trace.push_back(-1);
	}

	for(int i = n - 2; i >= 0; i--) {
		maxi = 1;
		for(int j = i + 1; j < n; j++) {
			if(a[j] > a[i] && dp[j] + 1 >= dp[i]) {
				dp[i] = dp[j] + 1;
				trace[i] = j; 
			}
		}
		if(dp[i] >= maxLen) {
			maxLen = dp[i];
			coutIdx = i;
		}
	}
	cout << maxLen << endl;
	for(int i = coutIdx; i < n; i++) {
		if(i == -1) break;
		cout << a[i] << ' ';
		i = trace[i] - 1;
	}
}