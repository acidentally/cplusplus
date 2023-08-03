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
	bool check = true;
	int a[n], p[n], q[n], count[n + 5] = {};
	multiset<int> s;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if(count[a[i]] == 2) {
			check = false;		
		}
		count[a[i]]++;
	}
	if(sum < n * (n + 1) / 2 || !check) {
		cout << "NO" << endl;
		return;
	}
	vi list;
	for(int i = 1; i <= n; i++) {
		if(count[a[i]] == 0) {
			list.push_back(i);
		}
		else {
			p[i] = q[i] = a[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		if(count[a[i]] == 2) {
			
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}