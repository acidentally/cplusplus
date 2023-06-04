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
	int n; cin >> n;
	if(n == 1) {
		cout << 1;
		return 0;
	} else if(n == 2) {
		cout << 1 << endl;
		cout << 1 << ' ' << 1;
		return 0;
	} else {
		vi a, b;
		cout << 1 << endl << 1 << ' ' << 1 << endl;
		int idx = 3;
		b.push_back(1);b.push_back(1);
		while(idx <= n) {
			idx++;
			a.push_back(1);
			for(int i = 0; i < b.size() - 1; i++){
				a.push_back(b[i] + b[i + 1]);
			}
			a.push_back(b[b.size() - 1]);
			for(int i = 0; i < a.size(); i++) {
				cout << a[i] << ' ';
			}	
			cout << endl;
			b = a;
			a = vi();
		}
	}
}