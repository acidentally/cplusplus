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
	// freopen("gpt.inp", "r", stdin);
	// freopen("gpt.out", "w", stdout);

	double a, b, c; cin >> a >> b >> c;
	double delta = b * b - 4 * a * c;
	if(delta >= 0) {
		cout << fixed << setprecision(10) << "x1 = " << (-b + sqrt(delta)) / 2 / a << endl;
		cout << fixed << setprecision(10) << "x2 = " << (-b - sqrt(delta)) / 2 / a; 
	} else {
		delta = abs(delta);
		cout << fixed << setprecision(10) << "x1 = " << -b/2/a << " + " << sqrt(delta)/2/a << "i" << endl;
		cout << fixed << setprecision(10) << "x1 = " << -b/2/a << " - " << sqrt(delta)/2/a << "i" << endl;
	}
}