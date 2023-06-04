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


bool check = false;
int AB[21] = {};
int n;
void solve(int k) {
	if(k > n) {
		for(int i = 1; i <= n; i++) {
			if(AB[i] == 1) cout << 'A';
			else if(AB[i] == 2) cout << 'B';
		}
		cout << endl;
		return;
	}
	else {
		for(int i = 1; i <= 2; i++) {
			AB[k] = i;
			solve(k + 1);
			if(k > 1 && AB[k - 1] == 2 && AB[k] == 1) {
				AB[k] = 0;
				return;
			}
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	solve(1);
	// cout << AB[];
}