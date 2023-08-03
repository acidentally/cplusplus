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

int n, d, a[2010];
void solve() {
	cin >> n >> d;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} sort(a, a + n);
	for(int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i];
	}
	
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}