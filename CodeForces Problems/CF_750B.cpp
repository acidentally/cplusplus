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

int n, dis;
string s;
void solve() {
	cin >> n;
	int curPos = 0;
	for(int i = 0; i < n; i++) {
		cin >> dis >> s;
		if(curPos == 0 && s[0] != 'S') {
			cout << "NO";
			return;
		}
		if(curPos == 20000 && s[0] != 'N') {
			cout << "NO";
			return;
		}
		if(s[0] == 'S') curPos += dis;
		else if(s[0] == 'N') curPos -= dis;
		if(curPos < 0 || curPos > 20000) {
			cout << "NO";
			return;
		}
		// cout << curPos << ' ';
	}
	cout << ((curPos == 0) ? "YES" : "NO");
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}