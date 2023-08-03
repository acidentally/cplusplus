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
int fac[17] = {}, a[20] = {};
void init() {
	fac[1] = fac[0] = 1;
	for(int i = 2; i <= 16; i++) {
		fac[i] = fac[i - 1] * i;
	}
}
void reset(int k) {
	for(int i = 1; i <= k; i++) a[i] = i;
} 
int q, n, k;
void compute(int bel, int k, int a[20]) {
	if(bel < 1) return;

	int temp = ((k - 1) / fac[bel - 1] + 1);

	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != 0) cnt++;

		if(cnt == temp) {
			cout << a[i] << ' ';
			a[i] = 0;
			compute(bel - 1, k - (temp - 1) * fac[bel - 1], a);
			return;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> q;
	while(q--) {
		cin >> n >> k;
		reset(n);
		compute(n, k, a);
		cout << endl;
	}
}
