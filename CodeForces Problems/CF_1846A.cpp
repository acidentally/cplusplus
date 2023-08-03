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

int n, a, b;
void solve() {
	cin >> n;
	int cnt = n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		if(b >= a) cnt--;
	}
	cout << cnt << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}