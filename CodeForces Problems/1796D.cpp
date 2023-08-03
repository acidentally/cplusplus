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
int cinTemp;

void solve(n, k, x){
	vi a;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
	}

}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	int n, k, x;
	while(tc--) {
		cin >> n >> k >> x;
		solve(n, k, x);
	}
}