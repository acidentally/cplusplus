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

int const maxn = 2e5 + 10;
int n, m, q, l, r, cnt1 = 0;
char x;
bool a[maxn] = {};

void solve() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[x - '0'] = 1;
		if(x == '1') cnt1++;
	}
	while(m--) {
		cin >> l >> r;
		if(find(l) != l) {
			
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}