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

int n, k, a[9], ans = 0, x;
vi res;
bool vis[9];
set<int> st;
void DFS(int x, int idx) {
	if(res.size() == k) {
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << endl;
		ans++;
		return;
	}
	for(int i = 0; i < n; i++) {
		if(i == idx) continue;
		res.push_back(a[i]);
		DFS(a[i], i);
		res.pop_back();
	}
}
void solve() {
	cin >> k >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n)
	for(int i = 0; i < n; i++) {
		res = vi();
		res.push_back(a[i]);
		DFS(a[i], i);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}