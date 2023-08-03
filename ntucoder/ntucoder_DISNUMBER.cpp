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
#define maxima 9999999999


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int a[20], F[20][20];
bool startCheck[10];

int thu(int idx, bool restricted, stack<int>) {
	if(idx < 0) {

	}
}

int G(string x) {
	for(int i = 0; i < x.size(); i++) {
		a[x.size() - 1 - i] = x[i];
	}
	return thu(x.size() - 1, true, 0);
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	string L, R; cin >> L >> R;
	bool d = false;
	for(int i = 0; i < L.size(); i++) {
		if(!startCheck[L[i] - 48]) startCheck[L[i] - 48] ^= 1;
		else d = true;
	}
	memset(F, -1, sizeof(F));
	cout << G(R) - G(L) + d;
}