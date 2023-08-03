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
int n = 8;
stack<bool> banco[13][13];
int cnt = 0, maxi = 0;
bool ngang[13];
int giatri[10][10];
void DFS(int k) {
	if(k > n) {
		maxi = max(maxi, cnt);
	} else {
		for(int i = 1; i <= n; i++) {
			if(banco[k][i].empty() && !ngang[i]) {

				ngang[i] = true;
				banco[k][i].push(true);
				int d = k + 1;
				for(int j = i + 1; j <= n && d <= n; j++) {
					banco[d][j].push(true);
					d++;
				}
				d = k + 1;
				for(int j = i - 1; j >= 1 && d <= n ; j--) {
					banco[d][j].push(true);
					d++;
				}
				cnt += giatri[k][i];
				DFS(k + 1);
				cnt -= giatri[k][i];
				ngang[i] = false;
				banco[k][i].pop();
				d = k + 1;
				for(int j = i + 1; j <= n && d <= n; j++) {
					banco[d][j].pop();
					d++;
				}
				d = k + 1;
				for(int j = i - 1; j >= 1 && d <= n ; j--) {
					banco[d][j].pop();
					d++;
				}
			}
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	// cin >> n;
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			cin >> giatri[i][j];
		}
	}
	DFS(1);
	cout << maxi;
}