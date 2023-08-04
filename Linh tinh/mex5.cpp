
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
int const maxn = 1e5 + 10;

int n, c, x;
void solve() {
	cin >> n >> c;
	int cnt[c + 10] = {};
	for(int i = 0; i < n; i++) {
		cin >> x;
		cnt[x % c]++;
	}
	int mini = LLONG_MAX;
	for(int i = 0; i < c; i++) {
		mini = min(mini, cnt[i]);
	}
	for(int i = 0; i < c; i++) {
		cnt[i] -= mini;
	}
	cnt[c] = cnt[0];
	// cout << mini << endl;
	for(int i = 1; i <= c; i++) {
		if(cnt[i] == 0) {
			cout << mini * c + i;
			return;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}