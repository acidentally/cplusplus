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

char x; 
int maxi = 0, mini = (int)1e18, cur = 0;
vector<bool> a;
void solve() {
	while(cin >> x) {
		a.push_back((x == '(') ? 1 : 0);
		if(x == '(') cur++;
		else cur--;
		maxi = max(maxi, cur);
		mini = min(mini, cur);
	}
	cout << maxi << ' ' << mini << endl;
	vector< vector< char> > ans(maxi - mini + 1, vector<char>(200, '.'));
	int cur = -mini;
	for(int i = 0; i < a.size(); i++) {
		if(a[i]) {
			ans[cur][i] = '/';
			cur++;
		} else {
			cur--;
			ans[cur][i] = 92;
		}
	}
	// cout << 0;
	int sizes = maxi - mini + 1;
	for(int i = maxi - mini - 1; i >= 0; i--) {
		for(int j = 0; j < a.size(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}