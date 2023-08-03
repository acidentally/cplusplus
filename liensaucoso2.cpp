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
	char x;
	vector<char> a;
	while(cin >> x) {
		a.push_back(x);
	}
	int i;
	for(i = a.size() - 1; i >= 0; i--) {
		if(a[i] == '1') {
			a[i] = '0';
		}
		else if(a[i] == '0') {
			a[i] = '1';
			break;
		}
	}
	if(i == -1) {
		cout << 1;
		for(int i = 0; i < a.size(); i++) {
			cout << 0;
		}
		return 0;
	}
	int startIdx = 0;
	while(a[startIdx] == '0') startIdx++;
	while(startIdx < a.size()) {
		cout << a[startIdx];
		startIdx++;
	}
}