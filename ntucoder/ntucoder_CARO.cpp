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

char a[30][30];
int n;

bool searchHang(int idx, char c) {
	int cur = 0;
	for(int i = 0; i < n; i++) {
		if(a[idx][i + 1] != c) cur = 0;
		else if(a[idx][i + 1] == c) cur++;
		if(cur == 5) {
			return true;
		}
	}
	return 0;
}

bool searchCol(int idx, char c) {
	int cur = 0;
	for(int i = 0; i < n; i++) {
		if(a[i + 1][idx] != c) cur = 0;
		else if(a[i + 1][idx] == c) cur++;
		if(cur == 5) {
			return true;
		}
	}
	return 0;
}

bool searchDiag1(char c) {
	int x = 1, y, cur;
	int t = n - 4;
	while(t > 0) {
		y = t;
		x = 1;
		cur = 0;
		while(x <= n) {
			if(a[x][y] != c) cur = 0;
			else if(a[x][y] == c) {
				cur++;
			}
			if(cur == 5) return true;
			x++;
			y++;
		}
		t--;
	}
	t = n - 4;
	while(t) {
		x = t;
		y = 1;
		cur = 0;
		while(y <= n) {
			if(a[x][y] != c) cur = 0;
			else if(a[x][y] == c) cur++;
			if(cur == 5) return true;
			x++;
			y++;
		}
		t--;
	}
	return 0;	
}	

bool searchDiag2(char c) {
	int t = 5;
	int x, y, cur;
	while(t <= n) {
		cur = 0;
		x = t;
		y = 1;
		while(x >= 1) {
			if(a[x][y] != c) cur = 0;
			else if(a[x][y] == c) cur++;
			if(cur == 5) return true;
			x--;
			y++;
		}
		t++;
	}
	t = 5;
	while(t <= n) {
		cur = 0;
		y = t;
		x = n;
		while(y >= 1) {
			if(a[x][y] != c) cur = 0;
			else if(a[x][y] == c) cur++;
			if(cur == 5) return true;
			y--;
			x--;
		}
		t++;
	}
	return 0;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	char c = 'o';
	for(int i = 1; i <= n; i++) {
		if(searchCol(i, c) || searchHang(i, c)) {
			cout << "Teo wins";
			return;
		}
	}
	c = 'x';
	for(int i = 1; i <= n; i++) {
		if(searchCol(i, c) || searchHang(i, c)) {
			cout << "Ti wins";
			return;
		}
	}
	if(searchDiag1('x') || searchDiag2('x')) {
		cout << "Ti wins";
		return;
	}
	if(searchDiag1('o') || searchDiag2('o')) {
		cout << "Teo wins";
		return;
	}
	cout << "Not yet";

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}


