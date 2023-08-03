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

int n, k;
int a[2010];

int cinn() {
	int n; cin >> n;
	return n;
}

void solve() {
	int sum = 0, d = 0, r = n - 1;
	for(int i = n - 1; i >= 0; i--) {
		sum += a[i];
		if(sum == k) {
			d++;
			sum -= a[r];
			r--;
		} else if(sum > k) {
			while(sum > k && r > -1) {
				sum -= a[r];
				r--;
			}
			if(sum == k) {
				d++;
				sum -= a[r];
				r--;
			}
		}
	}
	cout << d;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve();
}