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
void solve() {
	cin >> n;
	map<int, int> mapp;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		mapp[x] = i;
	}
	int ans = 1;
	for(int i = 1; i < n; i++) {
		if(mapp[i] > mapp[i + 1]) ans++;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
