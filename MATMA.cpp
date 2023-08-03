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
int n_(int k) {
	return (k + 1)/m - 1;
}
int m_(int k) {
	return k%m; 
}
char tempChar;
int luu[101][101];
bool check[101][101] = {};
void DFS(int k) {
	if(check[n_(k)][m_(k)]) {
		DFS(k + 1);
	}
	else {
		if(n_(k) > 1 && !check[n_(k)][m_(k)]) {
			DFS(k - n)
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> tempChar;
			luu[i][j] = tempChar - 'A';
		}
	}
}