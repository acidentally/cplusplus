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
void solve(int k) {
	int luu = k;
	int d = 10, cnt = 1;
	bool mid = false;
	while(k / d) {
		d *= 10;
		cnt++;
	}
	if(cnt % 2 == 1) {
		mid = true;
	}
	cnt /= 2;
	stack<int> temp;
	while(cnt--) {
		temp.push(k % 10);
		k /= 10;
	}
	if(mid) k /= 10;
	while(k) {
		if(k % 10 == temp.top()) {
			temp.pop();
			k /= 10;
		}
		else {
			break;
		}
	}
	if(k) return;
	else cout << luu << ' ';
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		solve(cinn());
	}
}