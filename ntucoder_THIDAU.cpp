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
int const maxn = 110;
vi days;
int a[maxn] = {}, n, k, x;
map<int, int> mapp;
vector<bool> check(maxn, 0);

int BFS(int ans, int idx, vector<bool> check) {
	vi::iterator ptr = lower_bound(days.begin(), days.end(), days[idx] + k);
	if(ptr == days.end()) {
		check[idx] = 0;
		return ans;
	}
	else {
		int couting = 0;
		while(ptr != days.end()) {
			couting = max(couting, BFS(ans + a[mapp[*ptr]], mapp[*ptr], check));
			ptr++;
		}
		check[idx] = 0;
		return couting;
	}
}

void solve() {
	cin >> n >> k;
	days.push_back(0);
	for(int i = 1; i <= n; i++) {
		cin >> x;
		days.push_back(x);
		mapp[x] = i;
	}
	int maxi = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!check[i]) ans = max(ans, BFS(a[i], i, check));
	}
	cout << ans;
	// cout << BFS(a[1], 1);	

}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}