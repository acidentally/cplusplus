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

char a[4][4];
void solve() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < 3; i++) {
		if((a[i][0] == a[i][1]) && (a[i][1] == a[i][2]) && (a[i][0] != '.')) {
			cout << a[i][0] << endl;
			return;
		}
		else if((a[0][i] == a[1][i]) && (a[1][i] == a[2][i]) && (a[0][i] != '.')) {
			cout << a[0][i] << endl;
			return;
		}
	}
	if((a[0][0] == a[1][1])&& (a[1][1] == a[2][2]) && (a[0][0] != '.')) {
		cout << a[0][0] << endl;
		return;
	}
	else if((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && (a[0][2] != '.')) {
		cout << a[0][0] << endl;
		return;
	}
	cout << "DRAW" << endl;
	return;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}