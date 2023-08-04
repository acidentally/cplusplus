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
int n;

int len(int a, int b) {
	return (a - b)/b + 1;
}
 
int calc(int a, int b) {
	if(a < b) return 0;
	else return (a / b * b + b) * len(a, b) / 2;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;

	while(tc--) {
		cin >> n;
		n--;
		cout << calc(n, 3) + calc(n, 5) - calc(n, 15) << endl;
	}
}