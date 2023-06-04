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
	int tc; cin >> tc;
	int n;
	set<int> cont;
	multiset<int> arrange;
	while(tc--) {
		cin >> n;
		cont = set<int>();
		arrange = multiset<int>();
		int a[n];
		fr(i,0,n) {
			cin >> a[i];
			cont.insert(a[i]);
			arrange.insert(a[i]);
		}
		multiset<int>::iterator temptr;
		for(set<int>::iterator p = cont.begin(); p != cont.end(); p++) {
			temptr = arrange.begin();
			cout << *p << ' ';
			while(*temptr != *p) {
				temptr++;
			}
			arrange.erase(temptr);
		}
		for(auto q : arrange) cout << q << ' ';
		cout << endl;
	}
}