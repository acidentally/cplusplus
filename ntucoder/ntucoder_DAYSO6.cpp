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
vi a, a1, a2, a3;
int n;

void solve() {
	vi b(n, 0);
	b[n - 2] = a2[n - 2] + a1[n - 1];
	for(int i = n - 3; i >= 0; i--) {
		
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int x; cin >> n;
	f(i,n) {
		cin >> x;
		a.push_back(x);
		a1.push_back(3 * x);
		a2.push_back(2 * x);
	}
}