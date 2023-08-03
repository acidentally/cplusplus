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
char a[3][3];
void checkCol(int idx, bool& found) {
	if(a[0][idx] == a[1][idx] && a[1][idx] == a[2][idx] && a[0][idx] != '.') {
		found = true;
		cout << a[0][idx] << endl;
	}
	return;
}
void checkRow(int idx, bool& found) {
	if(a[idx][0] == a[idx][1] && a[idx][1] == a[idx][2] && a[idx][0] != '.') {
		found = true;
		cout << a[idx][0] << endl;
	}
	return;
}
void solve() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	bool check = false;
	for(int i = 0; i < 3; i++) {
		if(check) return;
		checkCol(i, check);
		if(!check) 
		checkRow(i, check);
		if(check) return;
	}
	if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '.') {
		cout << a[0][0] << endl;
		return;
	}
	if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != '.') {
		cout << a[0][2] << endl;
		return;
	}
	cout << "DRAW" << endl;

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}