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

int n;
vi ans(55);

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	ans[0] = 1; ans[1] = 2; ans[2] = 3;
	if(n <= 2) {cout << ans[n]; return 0;}
	else {
		for(int i = 3; i <= n + 1; i++) {
			ans[i] = ans[i - 1] + 2 * ans[i - 2] + 3 * ans[i - 3];
		}
	}
	cout << ans[n];
}