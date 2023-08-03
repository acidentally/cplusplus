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
	int nam, nu; cin >> nam >> nu;

	multiset<int> boys, girls;

	for(int i = 0; i < nam; i++) {
		boys.insert(cinn());
	}
	for(int i = 0; i < nu; i++) {
		girls.insert(cinn());
	}
	multiset<int>::iterator ptrB = boys.begin(), ptrG = girls.begin();
	int cnt = 0;
	while(ptrB != boys.end() && ptrG != girls.end()) {
		if(*ptrB > *ptrG) {
			ptrB++;
			ptrG++;
			cnt++;
		} else if(*ptrB <= *ptrG) {
			ptrB++;
		}
	}
	cout << cnt;
}