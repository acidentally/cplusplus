/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

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


	multiset<int> a;
	set<int>::iterator ptr;


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	int n, x; cin >> n;

	while(n--) {
		cin >> x;
		a.insert(x);
		ptr = a.upper_bound(x);
		if(ptr != a.end()) {
			a.erase(ptr);
		}
	}
	cout << a.size();
}

ptr = upper_bound(a.begin(), a.end(), x);

ptr = a.upper_bound(x);