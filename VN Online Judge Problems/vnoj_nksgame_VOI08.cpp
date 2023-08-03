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
set<int> c;
void solve() {
	cin >> n;
	int b[n];
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> x; c.insert(x);
	}
	set<int>::iterator temp;
	int ans = abs(b[0] + *c.begin());
	for(int i = 0; i < n; i++){
		temp = c.lower_bound(-b[i]);
		if(temp == c.end()) {
			temp--;
			ans = min(ans, abs(*temp + b[i]));
		} else {
			if(temp != c.begin()) {
				temp--;
				if(temp != c.begin()) temp--;
			}
			for(int j = 0; j <= 5 && temp != c.end(); j++) {
				ans = min(ans, abs(*temp + b[i]));
				temp++;
			}
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}