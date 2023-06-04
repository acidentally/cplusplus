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
int cinTemp;
int cinn() {
	int n; cin >> n;
	return n;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, k; cin >> n >> k;
	vi a, p;
	deque<int> hold;
	multiset<int> minHolder;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
	}
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		p.push_back(cinTemp);
	}
	int d = 0, mini = p[0];
	int ans = 0;
	while(d < n) {
		hold.push_back(p[d]);
		minHolder.insert(p[d]);
		mini = min(mini, p[d]);
		if(hold.size() > k + 1) {
			minHolder.erase(hold.front());
			hold.pop_front();
			mini = *minHolder.begin();
		}
		// cout << a[d] * mini << endl;
		ans += a[d] * mini;
		d++;
	}
	cout << ans;
}