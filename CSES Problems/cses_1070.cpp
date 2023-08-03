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
	int n; cin >> n;
	if(n == 1) cout << 1;
	else if(n <= 3) cout << "NO SOLUTION";
	else {
		if(n % 2 == 0) {
			int k = n - 1;
			while(k > 0) {
				cout << k << ' '; k -= 2;;
			}
			while(n > 0) {
				cout << n << ' '; n -= 2;
			}
		}
		else if(n % 2 == 1) {
			int k = n - 1;
			while(n > 0) {
				cout << n << ' '; n -= 2;
			}
			while(k > 0) {
				cout << k << ' '; k -= 2;
			}
		}
	}
}
