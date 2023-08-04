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
	int n, x;
	cin >> n >> x;
	int t = 1;
	for(int i = 2; i <= x; i++) {
		if(x % i == 0) {
			t *= i;
			while(x % i == 0) x/= i;
		}
	}
	int t1;
	for(int i = 1; i < n; i++) {
		t1 = 1;
		cin >> x;
		for(int i = 2; i <= x; i++) {
			if(x % i == 0) {
				t1 *= i;
				while(x % i == 0) x /= i;
			}
		}
		if(t1 != t) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}