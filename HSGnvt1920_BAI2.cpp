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

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int H, M; cin >> H >> M;

	int ans = 0;
	for(int i = 0; i <= H; i++) {
		if(i == H) {
			if(H < 10) {
				for(int j = 0; j <= M; j++) {
					if(j == H || j == H*11) ans++;
				}
			} else if(H == 11 || H == 22) {
				for(int j = 0; j <= M; j++) {
					// cout << H/10 << endl;
					if(j == H/10 || j == H) ans++;
				}
			}
		} else {
			if(i < 10) ans++;
			if(i == 11 || i == 22 || i <= 5) ans++;
		}
	}
	cout << ans;
}
// 0 0
// 1 1 	
// 1 11
// 2 2
// 2 22
// 3 3
// 3 33
// 4 4
// 4 44
// 5 5
// 5 55
// 6 6
// 7 7
// 8 8
// 9 9
// 11 1
// 11 11

