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
int cnt = 0;
void solve(multiset<int> boys, multiset<int> girls) {
	if(boys.size() == 0 || girls.size() == 0) return;
	multiset<int>::iterator ptrB = boys.begin(), ptrG = girls.begin();
	while(ptrB != boys.end() && ptrG != girls.end()) {
		if(*ptrB > *ptrG) {
			ptrB++;
			ptrG++;
			cnt++;
		} else if(*ptrB <= *ptrG) {
			ptrB++;
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	multiset<int> posNam, negNam, posNu, negNu;

	fr(i,0,n) {
		cin >> cinTemp;
		if(cinTemp > 0) {
			posNam.insert(cinTemp);
		}
		else negNam.insert(-cinTemp);
	}
	fr(i,0,n) {
		cin >> cinTemp;
		if(cinTemp > 0) {
			posNu.insert(cinTemp);
		} else negNu.insert(-cinTemp);
	}
	solve(negNam, posNu);
	solve(negNu, posNam);
	cout << cnt;
}