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

string s, p, t;
void solve() {
	cin >> s >> t >> p;
	int l[26] = {};
	if(s.size() > t.size()) {
		cout << "NO" << endl;
		return;
	} else if(s.size() == t.size()) {
		if(s == t) cout << "YES" << endl;
		else cout << "NO" << endl;
		return;
	}
	for(int i = 0; i < p.size(); i++) {
		l[p[i] - 'a']++;
	}
	int ps = 0, pt = 0;
	int cursize = s.size();
	while(pt < t.size() && cursize <= t.size()) {
		if(ps == s.size() || s[ps] != t[pt]) {
			if(l[t[pt] - 'a'] != 0) {
				l[t[pt] - 'a']--;
				cursize++;
			} else {
				cout << "NO" << endl;
				return;
			}
		}
		else if(s[ps] == t[pt]) {
			ps++;
		}
		pt++;
	}
	if(cursize > t.size()) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}