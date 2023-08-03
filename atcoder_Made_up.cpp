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
int n, x;
vi a, b;
map<int, int> c;
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i = 0; i < n; i++) {
		cin >> x;
		c[x - 1]++;
	}
	int pA = 0, pB = 0, ans = 0;
	while(pA < n && pB < n) {
		if(a[pA] > b[pB]) {
			cout << "pB : " << pB << endl;
			pB++;
		} else if(a[pA] < b[pB]) {
			cout << "pA : "  << pA << endl;
			pA++;
		}
		else {
			ans += c[pB];
			pB++;
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}