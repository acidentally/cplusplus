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

void solve(vi a, int n) {
	vi len(n, 0);
	vi trace(n, 0);
	for(int i = 0; i < n; i++) {
		len[i] = 1;
	}
	int maxi = 1;
	int startIdx;
	for(int i = n - 2; i >= 0; i--) {
		for(int j = i + 1; j < n; j++) {
			if(a[j] <= a[i]) continue;
			else {
				if(len[j] + 1 > len[i]) {
					len[i] = len[j] + 1;
					trace[i] = j;
				}
				if(len[i] > maxi) {
					maxi = len[i];
					startIdx = i;
				}
			}
		}
	}
	cout << maxi << endl;
	if(maxi == 1) {
		cout << a[0];
		return;
	}
	while(maxi--) {
		cout << a[startIdx] << ' ';
		startIdx = trace[startIdx];
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	vi a;
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	solve(a, n);
}