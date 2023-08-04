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

int n, x;
bool a[6000010] = {};
void solve() {
	cin >> n;
	int cnt = 1;
	set<int> s;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a[x] = 1;
	}
	while(a[cnt]) cnt++;
	cout << cnt;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}