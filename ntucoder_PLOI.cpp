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

int n, x, ans = 0;
int calls[12];
vi a;

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		calls[x]++;
		if(calls[x] == 3) {
			a.push_back(x);
			calls[x] = 0;
			ans++;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}