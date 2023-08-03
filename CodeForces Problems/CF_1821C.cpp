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

string s;
int log2_(int k) {
	if(k == 0) return 0;
	int ans = 0;
	while(k) {
		ans++;
		k >>= 1;
	}
	return ans;
}
int mainAns;
void solve() {
	cin >> s;
	mainAns = 1000;
	for(char x = 'a'; x <= 'z'; x++) {
		int l = 0, ans = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == x) {
				ans = max(ans, log2_(i - l));
				l = i + 1;
			}
		}
		ans = max(log2_(s.size() - l), ans);
		if(l != 0) mainAns = min(mainAns, ans);
	}
	cout << mainAns << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
	// cout << log2_(1);
}