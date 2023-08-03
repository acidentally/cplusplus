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

int const maxm = 5e5 + 10;
int const maxn = 15;

char x;
int n, m, q, k;
multiset<int> S;

void compute(int num, int k) {
	
}

void solve() {
	cin >> n >> m >> q;
	int w[n + 10];
	for(int i = n; i >= 1; i--) {
		cin >> w[i];
	}
	int num = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> x;
			num = (num << 1) + (x - '0');
		}
		S.insert(num);
		num = 0;
	}
	while(q--) {
		num = 0;
		for(int i = 0; i < n; i++) {
			cin >> x;
			num = (num << 1) + (x - '0');
		}
		cin >> k;
		compute(num, k);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}