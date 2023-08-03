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
	int a[n + 5];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0;
	cout << 1 << ' ';
	for(int i = 2; i <= n; i++) {
		while(l < i && a[l + 1] < i - l) {
			l++;
		}
		cout << i - l << ' ';
	}	
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}