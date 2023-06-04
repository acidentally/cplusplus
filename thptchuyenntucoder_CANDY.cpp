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
#define maxn (int)1e19


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
int cinTemp;

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	vi a;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		sum += cinTemp;
		a.push_back(sum);
	}
	int mini = maxn;
	for(int i = 0; i < n; i++) {
		mini = min(mini, abs(sum - 2*a[i]));
	}
	cout << mini;
}