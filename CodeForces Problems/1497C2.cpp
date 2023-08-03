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
	int tc; cin >> tc;
	int n, k, count;
	while(tc--) {
		cin >> n >> k;
		count = 1;
		while(k > 3) {
			cout << 1 << ' ';	
			k--; n--;
		}
		while(n % 2 == 0 && n > 3) {
			count *= 2;
			n /= 2;
		}
		cout << count << ' ' << count*(n-1)/2 << ' ' << count*(n-1)/2;
		if(tc > 0) cout << endl;
	}
}