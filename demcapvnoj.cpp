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
int cinTemp;

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	stack<pair<int, int> > a;
	cin >> cinTemp; a.push({cinTemp, 1});
	int res = 0;

	for(int i = 0; i < n - 1; i++) {
		cin >> cinTemp;
		if(cinTemp == a.top().fi) {
			a.top().se++;
			res += (a.size() > 1) ? a.top().se : a.top().se - 1;
		}

		else if(cinTemp > a.top().fi) {
			while(!a.empty() && cinTemp > a.top().fi) {
				res++;
				if(a.top().se == 1) a.pop();
				else a.top().se--;
			} 
			
			if(a.empty()) {
				a.push({cinTemp, 1});
			} 

			else {
				if(cinTemp == a.top().fi) a.top().se++;
				else a.push({cinTemp, 1});
				res += (a.size() > 1) ? a.top().se : a.top().se - 1;
			}
		}
		else if(cinTemp < a.top().fi) {
			res++;
			a.push({cinTemp, 1});
		}
	}
	cout << res;
}