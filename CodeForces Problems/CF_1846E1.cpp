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
void solve() {
	cin >> n;
	vi a;
	for(int i = 2; i * i <= n - 1; i++) {
		if((n - 1) % i == 0) a.push_back(i);
	}
	// for(auto i : a) cout << i << ' ';
	if(a.empty()) {
		// cout << n << endl;
		return;
	}
	for(int i = 0; i < a.size(); i++) {
		int power = n * (a[i] - 1) + 1, cnt = 1;
		while(power % a[i] == 0) {
			// cout << power << ' ';
			power /= a[i];
			cnt++;
		}
		if(power == 1 && cnt >= 3) {
			cout << n << endl;
			return;
		}
	}
	// cout << n << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}