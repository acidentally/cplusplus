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
int fac(int n) {
	if(n == 1) return 1;
	else return n * fac(n - 1);
}
map<int, int> mapp;
string s;
void couting() {
	int k = fac(s.size());
	map<int, int>::iterator ptr = mapp.begin();
	while(ptr != mapp.end()) {
		// cout << ptr -> se << endl;
		k /= fac(ptr -> se);
		ptr++;
	}
	cout << k << endl;}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	getline(cin, s);
	char a[s.size()];
	for(int i = 0; i < s.size(); i++) {
		mapp[s[i] - 'a']++;
		a[i] = s[i];
	}
	couting();
	sort(a, a + s.size());
	do {
		for(int i = 0; i < s.size(); i++) {
			cout << a[i];
		}
		cout << endl;
	} while(next_permutation(a, a + s.size()));
}