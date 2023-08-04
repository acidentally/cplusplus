/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int q;
string s1;
void xuli(string s) {
	if(s.size() & 1) {
		cout << "NO" << endl;
		return;
	}
	vector<char> c;
	int cntMO = 0, cntDONG = 0;
	for(int i = 0; i < s.size(); i++) {
		if(c.empty()) {
			c.push_back(s[i]);
			continue;
		}
		if(c.back() + s[i] == 81) {
			c.pop_back();
		} else c.push_back(s[i]);
	}
	if(c.empty()) {
		cout << "YES" << endl;
		return;
	}
	int idx = 0;
	if(c[0] == '?' && c[1] == '?') {
		c[0] = 'a';
		c[1] = 'a';
		idx = 2;
	}
	for(int i = idx + 1; i < c.size() - 1; i++) {
		if(c[i] != '?') continue;
		if(c[i - 1] == '(') {
			c[i] = 'a';
			c[i - 1] = 'a';
		}
		else if(c[i + 1] == ')') {
			c[i] = 'a';
			c[i + 1] = 'a';
		}
	}
	int ans = 0;
	for(int i = 0; i < c.size(); i++) {
		if(c[i] == 'a') continue;
		else if(c[i] == '(') ans++;
		else if(c[i] == ')' && ans == 0) {
			cout << "NO" << endl;
			return;
		} else ans--;
	}
	cout << ((ans == 0) ? "YES" : "NO") << endl;
}
void solve() {
	cin >> q;
	while(q--) {
		cin >> s1;
		xuli(s1);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}