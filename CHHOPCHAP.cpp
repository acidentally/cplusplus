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

int holder[10] = {}, a[10] = {};
bool check[10] = {};
int k, n, cinTemp;
int d = 0;
map<int, bool> mapp;
void DFS(int m) {
	if(m > k) {
		for(int i = 1; i <= k; i++) {
			if(mapp[holder[i]]) cout << -holder[i] << endl;
			else cout << holder[i] << ' ';
		}
		cout << endl;
		d++; return;
	} else {
		for(int i = 1; i <= n; i++) {
			if(!check[i]) {
				check[i] = true;
				holder[m] = a[i];
				DFS(m + 1);
				check[i] = false;
			}
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> k >> n;
	for(int i = 1; i <= n; i++) {
		cin >> cinTemp;
		if(cinTemp < 0) mapp[cinTemp] = true;
		a[i] = abs(cinTemp);
	}
	sort(a + 1, a + n + 1);
	DFS(1); cout << d;
}