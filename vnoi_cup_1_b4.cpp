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

int n, k;
string s, t;
vi a;
void solve() {
	cin >> n >> k;
	cin >> s >> t;
	int a[n];
	cin >> a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int l, r;
	vector< pair<int, int> > count;
	for(int i = 0; i < n; i++) {
		if(s[i] != t[i]) {
			cout << i << endl;
			l = i++;
			while(s[i] != t[i]) {
				i++;
			}
			r = i;
			cout << i << endl;
		}
		count.push_back({l, r});
	}
	// for(int i = 0; i < count.size(); i++) {
	// 	cout << count[i].fi << ' ' << count[i].se << endl;
	// }
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}