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
#define mp(a,b) make_pair(a,b)


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
	int n, ans = 0; cin >> n;
	int temp;
	queue<pair<int, int> > couting;
	n *= 2;
	for(int i = 2; i * i <= n; i++) {
		// cout << i << ' ' << n << endl;
		if(n % i == 0 && (n/i - i - 1 )% 2 == 0) {
			// cout << "LMAOO";
			ans++;
			temp = (n/i - i - 1)/2;
			couting.push(make_pair(temp + 1, temp + i));
		}
	}
	cout << ans << endl;
	while(!couting.empty()) {
		cout << couting.front().fi << ' ' << couting.front().se << endl;
		couting.pop();
	}
}