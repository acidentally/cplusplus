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

string s, x;
void solve() {
	unordered_map<string, bool> mp;
	while(1) {
		getline(cin, x);
		if(x == "BOOK") break;
		mp[x] = !mp[x];
	}
	for(auto i : mp) {
		if(i.se == 1) cout << i.fi;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}