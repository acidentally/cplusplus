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


int sqr(int n) {return (n * n) % 210;}

int modPow(int n) {
	if(n == 0) return 1;
	else if(n == 1) return 10;
	else {
		if(n % 2 == 0) {
			return sqr(modPow(n/2)) % 210;
		}
		else return (10 * sqr(modPow(n/2))) % 210;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	if(n < 3) {
		cout << -1;
		return 0;
	}
	else if(n == 3) {
		cout << 210;
		return 0;
	}
	int a = modPow(n - 1);
	string s = "1";
	for(int i = 1; i <= n - 1; i++) {
		s = s + '0';
	}
	a = 210 - a;
	if(a >= 0) s.erase(s.size() - 1, 1);
	if(a >= 10) s.erase(s.size() - 1, 1);
	if(a >= 100) s.erase(s.size() - 1, 1);
	cout << s << a;
}
