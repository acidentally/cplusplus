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
#define pb push_back

int nxt(){
	int n; cin >> n; return n;
}
int n, c;
void solve() {
	cin >> n >> c;
	vi a;
	for(int i = 0; i < n; i++) {
		a.pb(nxt());
	}
	if(c >= 0) {
		sort(a.begin(), a.end());
		for(auto u : a) cout << u << ' ';
		cout << endl;
		return;
	}	
	c = -c;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) {

	}
	solve();
}