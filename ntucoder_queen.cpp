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
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int cinn() {
	int n; cin >> n;
	return n;
}
int x, y;
bool c1[20] = {}, c2[20] = {}, ngang[10] = {};
bool check = false;
bool luu[20][20] = {};
void DFS(int k) {
	if(k == x) {
		DFS(k + 1);
	}
	else if(k > 8) {
		for(int i = 1; i <= 8; i++) {
			for(int j = 1; j <= 8; j++) {
				if(luu[j][i]) cout << 'w';
				else cout << '.';
			}
			cout << endl;
		}
		check = true; 
	} else if(!check){
		for(int i = 1; i <= 8 && !check; i++) {
			if(!ngang[i] && !c1[k + i - 2] && !c2[k - i + 7]) {
				ngang[i] = true;
				c1[k + i - 2] = true;
				c2[k - i + 7] = true;
				luu[k][i] = true;
				DFS(k + 1);
				ngang[i] = 0;
				c1[k + i - 2] = false;
				c2[k - i + 7] = false;
				luu[k][i] = false;
			}
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> y >> x;
	ngang[y] = true;
	c1[y + x - 2] = true;
	c2[x - y + 7] = true;
	luu[x][y] = true;
	DFS(1);
}