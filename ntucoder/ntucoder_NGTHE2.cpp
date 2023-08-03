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
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	multiset<int> st;
	multiset<int>::iterator ptr1;
	st.insert(a[n - 1]);
	int ans = 0, maxi = a[n - 1], mini = a[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if(a[i] > maxi) {
			ans += st.size();
			maxi = a[i];
		} else if(a[i] <= mini) {
			mini = a[i];
		} else {
			ptr1 = st.upper_bound(a[i] - 1);
			ans += distance(st.begin(), ptr1) + 1;
		}
		st.insert(a[i]);
	}
	cout << ans << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}