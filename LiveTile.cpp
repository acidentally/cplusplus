/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

char a[30][6];
int n, ans = 0;
void fillM(int x) {
	for(int i = x; i <= x + 1; i++) {
		for(int j = 1; j <= 4; j++) {
			a[i][j] = 'M';
		}
	}
	ans++;
}
void fillS(int x, int y) {

	for(int i = x; i <= x + 1; i++) {
		for(int j = y; j <= y + 1; j++) {
			a[i][j] = 'S';
		}
	}
	ans += 3;
}
void couting() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 6; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}
void fillL(int x) {
	for(int i = x; i <= x + 1; i++) {
		for(int j = 1; j <= 4; j++) {
			a[i][j] = 'L';
		}
	}
	ans--;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int m; cin >> n >> m;
	int _i;
	for(int i = 1; i <= n/2; i++) {
		_i = 2*i - 1;
		for(int j = 1; j < 5; j++) {
			a[_i][j] = 'L';
			a[_i + 1][j] = 'L';
		}
		a[_i][5] = a[_i][6] = 'M';
		a[_i + 1][5] = a[_i + 1][6] = 'M';
		ans += 2;
 	}
 	if(n % 2) {
 		for(int i = 1; i <= 6; i++) {
 			a[n][i] = 'S';
 		}
 		ans += 6;
 	}
 	int x, y;
 	if(ans > m) {
 		cout << "NO";
 		return 0;
 	} else if(ans < m) {
 		x = 1; y = 1;
 		while(ans < m && x <= n / 2 * 2) {
 			fillM(x);
 			x += 2;
 		}
 		x = n / 2 * 2 - 1; y = 1;
 		while(ans < m && x >= 2) {
 			if(y < 7) {
 				fillS(x, y);
 				y += 2;
 			}
 			else if(y >= 7) {
 				y = 1;
 				x -= 2;
 			}
 		}
 	}
 	x -= 2;
 	while(ans > m && x > 0) {
 		fillL(x);
 	}
 	if(ans == m) {
 		cout << "YES" << endl;
 		couting();
 	} else cout << "NO";
}