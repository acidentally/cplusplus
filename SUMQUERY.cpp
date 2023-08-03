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
	int n, q; cin >> n >> q;
	int a[n] = {}, l , r;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < q; i++) {
		cin >> cinTemp;
		if(cinTemp == 1) {
			cin >> l >> r;

		} else {
			cin >> l >> r;
			a[l - 1] = r;
		}
	}
}