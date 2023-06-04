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

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int m, n, k, cinTemp;

	cin >> m >> n >> k;

	multiset<int> A;
	map<int, int> _a;
	if(k == 0) {
		int cntA = 0, cntB = 0;
		for(int i = 0; i < m; i++) {
			cin >> cinTemp;
			if(cinTemp == 0) cntA++;
		}
		for(int i = 0; i < n; i++) {
			cin >> cinTemp;
			if(cinTemp == 0) cntB++;
		}
		cout << cntA * n + cntB * m - cntA * cntB;
	}
	else if(k != 0) {
		for(int i = 0; i < m; i++) {
			cin >> cinTemp;	
			if(cinTemp == 0) continue;

			if(k % cinTemp == 0 && A.count(k / cinTemp) == 0) {
				A.insert(k / cinTemp);
				_a[k/cinTemp]++;
			}
			else if(k % cinTemp == 0 && A.count(k / cinTemp) > 0) _a[k/cinTemp]++; 
		}
		int ans = 0;

		for(int i = 0; i < n; i++) {
			cin >> cinTemp;
			if(cinTemp == 0) continue;
			else if(A.count(cinTemp) > 0) {
				ans += _a[cinTemp];
			}
		}
		cout << ans;
	}
}