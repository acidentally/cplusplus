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
int min_dis(char a, char b) {
	if(a > b) swap(a, b);
	return min(abs(a - b), abs(a + 26 - b));
}
void solve() {
	cin >> s;
	int ans = 0;
	for(int i = 1; i < s.size(); i++) {
		ans += min_dis(s[i], s[i - 1]);
	}
	cout << ans + min_dis('a', s[0]);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);	
	solve();
}