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
int n;
set<int> s;
bool luu[100001];
void solve(int k) {
	if(!luu[k]) {
		luu[k] = true;
	} else if(luu[k] || k == 0) return;
	for(int i = 1; i * i <= k; i++) {
		if(k % i == 0) {
			s.insert((i - 1) * (k/i + 1));
			solve((i - 1) * (k/i + 1));
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	solve(n);
	s.insert(0);
	cout << s.size() << endl;
	set<int>::iterator ptr = s.begin();
	while(ptr != s.end()) {
		cout << *ptr << ' ';
		ptr++;
	}

}