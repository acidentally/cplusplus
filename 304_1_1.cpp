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
	// freopen("brodo.inp", "r", stdin);
	// freopen("brodo.out", "w", stdout);
	int ans = 0, cinTemp;
	int n; cin >> n;
	vi a;

	int check[n] = {};

	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
		// b.push_back(0);
	}
	pair<int, int> b[n + 10];
	for(int i = 0; i < n + 10; i++) {
		b[i] = make_pair(0,0);
	}
	b[n - 1].fi = 1; b[n - 1].se = 0;
	b[n - 2].fi = 2; b[n - 2].se = b[n - 1].fi - b[n - 2].fi;

	for(int i = n - 3; i >= 0; i--) {
		int maxi = b[i + 1].fi, tempd = b[i + 1].se;
		for(int j = i + 1; j < n; j++) {
			if(b[j].fi > maxi && b[j].fi - b[i].fi == b[j].se) {
				maxi = b[j].fi + 1;
				tempd = b[j].se;
			}
		}
		b[i].fi = maxi ;
		b[i].se = tempd;
	}	

	for(int i = 0; i < n; i++) {
		if(!check[i]) {
			ans++;
			check[i] = true;
			int temp = b[i].fi;
			for(int j = i + 1; j < n; j++) {
				while(a[j] < temp + b[i].se) {
					j++;
				}
				if(a[j] > temp + b[i].fi) {
					continue;
				} else {
					check[j] = true;
					temp += b[i].se;
				}
			}
		}
	}
	cout << ans;
}