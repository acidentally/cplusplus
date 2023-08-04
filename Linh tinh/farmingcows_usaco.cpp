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
vi a;
void solve() {
	cin >> n;
	int mini[7] = {}, maxi[7] = {}; 
	cin >> x; a.push_back(x % 7);
	int interupt = x % 7;
	mini[interupt] = 0;
	for(int i = 1; i < n; i++) {
		cin >> x;
		a.push_back((a[i - 1] + x) % 7);
		maxi[a[i]] = i;
		if(a[i] != interupt && mini[a[i]] == 0) mini[a[i]] = i;
	}
	int ans = 0;
	for(int i = 0; i < 7; i++) {
		ans = max(ans, maxi[i] - mini[i]);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	solve();
}