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

int a[51][51] = {};
int n;
int l = 0, r = 0, val = 1;
void build(int ngang) {
	if(val > n * n) return;
	if(ngang == 0) {
		while(r < n && a[l][r] == 0) {
			// cout << l << ' ' << r << endl;
			a[l][r] = val;
			val++;
			r++;
		}
		r--;
		l++;
		build(1);
	} 
	else if(ngang == 1) {
		while(l < n && a[l][r] == 0) {
			a[l][r] = val;
			val++;
			l++;
		}
		l--;
		r--;
		build(2);
	}
	else if(ngang == 2) {
		while(r >= 0 && a[l][r] == 0) {
			a[l][r] = val;
			val++;
			r--;
		} 
		r++; l--;
		build(3);
	}
	else {
		while(l >= 0 && a[l][r] == 0) {
			a[l][r] = val;
			val++;
			l--;
		}
		l++;
		r++;
		build(0);
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	build(0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}