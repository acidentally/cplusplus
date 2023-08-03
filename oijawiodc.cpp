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
	freopen("us.inp", "r", stdin);
	freopen("us.out", "w", stdout);
	int n; cin >> n;
	for(int k = 2; k <= n/2; k++) {
		if(2 * n % k != 0) continue;
		else if((2 * n / k + 1 - k) % 2 != 0) continue;
		else if( (2 * n / k + 1 - k) < 0 ) break;
		else cout << (2 * n / k + 1 - k)/2 << ' ' << (2 * n / k + 1 - k)/2 + k - 1 << endl;
	}
}

