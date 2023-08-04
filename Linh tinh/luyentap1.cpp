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
	int n, k, x; cin >> n >> k;
	k = min(k, n - k);
	int sum = 0, sum1 = 0;
	multiset<int> a;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.insert(x);
		sum += x;
	}

	multiset<int>::iterator ptr = a.begin();
	while(k--) {
		sum1 += *ptr;
		ptr++;
	}
	cout << abs(sum - 2*sum1);
}