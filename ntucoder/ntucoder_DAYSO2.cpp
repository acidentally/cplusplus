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
#define INF (int)1e18


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

int prod(vi a) {
	if(a.size() == 1) return -INF;
	vi b(a.size(), 0);
	
	int maxi = b[a.size() - 1] = a[a.size() - 1];
	for(int i = a.size() - 2; i > 0; i--)  {
		b[i] = max(a[i] + b[i + 1], a[i]);
		maxi = max(maxi, b[i]);
	}
	return maxi;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, x; cin >> n;
	int sum = 0, ans = 0;
	vi a;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	vi a1, a2, a3;
	a1.push_back(0); a2.push_back(0); a3.push_back(0);
	for(int i = 0; 3 * i + 2 < n; i++) {
		a1.push_back(a[3*i] + a[3*i + 1] + a[3*i + 2]);
		if(3*i + 3 < n) a2.push_back(a[3*i + 1] + a[3*i + 2] + a[3*i + 3]);
		if(3*i + 4 < n) a3.push_back(a[3*i + 2] + a[3 * i + 3] + a[3 * i + 4]);
	}

	cout << max(prod(a1), max(prod(a2), prod(a3)));
}