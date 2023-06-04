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
void solve() {
	cin >> n;
	multiset<int> a, b;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.insert(x);
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		b.insert(x);
	}
	int sum = 0;
	multiset<int>::iterator ptra = a.begin();
	multiset<int>::reverse_iterator ptrb = b.rbegin();
	while(ptra != a.end() && ptrb != b.rend()) {
		sum += max(*ptra, *ptrb);
		ptra++;
		ptrb++;
	}
	cout << sum << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}