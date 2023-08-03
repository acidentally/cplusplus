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
	int n, m; cin >> n >> m;
	int b, c;
	set< pair<int, int> > a;
	for(int i = 0; i < n; i++) {
		cin >> b >> c;
		a.insert(make_pair(b, c));
	}
	set< pair<int, int> >::iterator ptr;
	pair<int, int> temp1 = *a.begin(), temp2;
	int cnt = temp1.se;
	for(ptr = a.begin(); ptr != a.end(); ptr++) {
		temp1 = *ptr;
		temp2 = *++ptr;
		if(ptr == a.end()) break;
		cnt += max(0ll, temp2.se - temp1.se);
		--ptr;
	}
	cout << cnt;

}