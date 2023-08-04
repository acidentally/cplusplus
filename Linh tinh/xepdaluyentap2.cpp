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
int n;
int squareroot(int l, int r) {
	if(l == r) return l;
	else {
		int mid = l + r >> 1;
		if(mid * mid < n) {
			return squareroot(mid + 1, r);
		} else return squareroot(l, mid);
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	int a = squareroot(1, n), b = a;
	while(a * b >= n) {
		b--;
	}
	b++;
	cout << min(a, b) << ' ' << max(a, b);
}