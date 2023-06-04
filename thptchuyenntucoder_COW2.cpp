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
int n, m, cinTemp, mainMin;
set<int> a;

void solve(int l, int r) {
	cout << l << ' ' << r << endl;

	if(l == r) {
		cout << max(l, mainMin); return;
	}
	int mid = (l + r)/2, cnt = 1;
	mainMin = 1e18;
	set<int>::iterator ptr = a.begin(), ptr2, temp;
	while(ptr != a.end()) {
		ptr2 = ptr;
		ptr = lower_bound(ptr, a.end(), *ptr + mid);
		if(ptr == a.end()) break;
		mainMin = min(mainMin, *ptr - *ptr2);
		cnt++;
	}
	cout << cnt << ' ' << mainMin << endl << endl;
	if(cnt < m) {
		solve(l, mid);
	} else if(cnt > m) {
		solve(mid + 1, r);
	} else if(cnt == m) {
		solve(mid, (r + mid)/2);
	}
}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	int mini = 1e18, maxi = 0;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.insert(cinTemp);
		mini = min(mini, cinTemp);
		maxi = max(maxi, cinTemp);
	}
	// cout << mini << ' ' << maxi << endl;
	solve(1, maxi - mini);
}