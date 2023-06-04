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
#define pi pair<int, int>


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
	string s; cin >> s;
	int temp = 0;
	int maxLen = 0, tempLen = 0, preLen = 0;
	int l = 0, r = 0;
	vector<pi> a;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '{') temp++;
		else if(s[i] == '}') {
			if(temp <= 0) {temp = 0;}
			else {
				temp--;
				if(temp == 0) {
					a.push_back({l, r});
					l = i + 1;
					r = i;
				}
			}
		}
		r++;
	}
	int ans = 0, idx = 0;
	for(int i = 0; i < a.size() - 1; i++) {
		// if(i == idx) continue;
		if(a[i].se == a[i + 1].fi) {
			continue;
		}
		else {
			ans = max(ans, a[i].se - a[idx].fi + 1);
			idx = i + 1;
		}
	}
	cout << ans;
}