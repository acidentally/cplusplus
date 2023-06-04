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
	freopen("X3.inp", "r", stdin);
	freopen("X3.out", "w", stdout);
	int n; cin >> n; 
	int idx; int cinTemp;

	vector<int> count(22,0);
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		idx = 1;
		while(cinTemp) {
			count[idx] += cinTemp % 2;
			cinTemp /= 2;
			idx++;
		}
	}
	// for(int i = 0; i < 22; i++) cout << count[i] << ' ';
	// 	cout << endl;
	vector<int> res;
	for(int i = 1; i < 22; i++) {
		if(count[i] == 0) res.push_back(0);
		int k = count[i];
		res.push_back(count[i] * (n - count[i]));
	}
	int ans = 0, temp = 0;
	// for(int i = 0; i < res.size(); i++) cout << res[i] << ' ';
	// 	cout << endl;
	for(int i = 0; i < res.size(); i++) {
		ans += res[i] * (1 << temp);
		temp++;
	}
	cout << ans;

}

