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
int const INF = 2e9;
int n, res = 0;

struct pi {
	int idx, firstVal, numTurns;
	pi() {
		idx = 0, firstVal = 0, numTurns = 0;
	}
	pi(int a, int b, int c) : idx(a), firstVal(b), numTurns(c) {}
};
void maximise(pi& a, pi b) { 
	if(a.numTurns > b.numTurns) a = b;
}
void solve() {
	cin >> n;
	int a[n + 10];
	pi p[n + 10];
	pi ans = pi(0, INF, INF);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int k = a[i] - i + 1;
		if(k <= 0) {
			cout << i;
			return;
		}
		p[i] = {i ,k, (k - 1)/n + 1};
		maximise(ans, p[i]);
	}
	cout << ans.idx;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}