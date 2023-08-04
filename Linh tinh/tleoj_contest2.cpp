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

int Te = 0, Ce = 0, Ve = 0;
void solve() {
	string s; cin >> s;
	int c[3] = {}, T = 0, C = 0, V = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'T') T++;
		if(s[i] == 'C') C++;
		if(s[i] == 'V') V++;
	}
	int ans = max(T, max(C, V));
	if(ans == T) Te++;
	else if(ans == V) Ve++;
	else if(ans == C) Ce++;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
	cout << Te << ' ' << Ve << ' ' << Ce;
}