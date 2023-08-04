/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int T[maxn] = {}, P[maxn][20] = {};
int h[maxn] = {};

void precompute() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; (1 << j) < n; j++) {
			P[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; i++) {
		P[i][0] = T[i];
	}
	for(int j = 1; 1 << j < n; j++) {
		for(int i = 1; i <= n; i++) {
			if(P[i][j - 1] != -1) {
				P[i][j] = P[ P[i][j - 1] ][j - 1];
			}
		}
	}
}
void LCA(int x, int y) {
	if(h[x] <= h[y]) swap(x, y);
	int log = 0, k = h[x];
	while(k) {
		log++;
		k >>= 1;
	}
	for(int i = log; i >= 0; i--) {
		if((h[x] - (1 << i)) >= h[y]) x = P[x][i];
	}	
	if(x == y) {
		cout << x << endl; 
		return;
	}
	// cout << x;
	for(int i = log; i >= 0; i--) {
		if(P[x][i] != -1 && P[x][i] != P[y][i]) {
			x = P[x][i];
			y = P[y][i];
		}
	}
	cout << T[x] << endl;
}

void solve() {
	//To LCA (Sparse Table) you need to build
	//1. The array P in which P[i][j] holds the (1 << j) parents of i
	//2. The array h is the depth of the node i from the root node
	//3. The array T is the direct parents of each node.

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}