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

int n;
int a[30][30] = {};
int sol[30][30] = {};
void xuli(int j) {
	vi b;
	for(int i = n; i > 0; i--) {
		if(a[i][j] == 0) continue;
		b.push_back(a[i][j]);
	}
	for(int i = 0; i < b.size() - 1; i++) {
		if(b[i] == b[i + 1]) {
			b[i] += b[i + 1];
			b[i + 1] = 0;
			i++;
		}
	}
	int cnt = 0;
	for(int i = n; i > 0 && cnt < b.size(); i--) {
		while(cnt < b.size() && b[cnt] == 0) cnt++;
		if(cnt >= b.size()) break;
		sol[i][j] = b[cnt];
		cnt++;
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for(int j = 1; j <= n; j++) {
		xuli(j);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << sol[i][j] << ' ';
		}
		cout << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}