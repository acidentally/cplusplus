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
int l, r;
vector<bool> isPrime (100, false);
void eratos() {
	for(int i = 0; i < 100; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i <= 100; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j <= 100; j += i) {
				isPrime[j] = false;
			}
		}
	}
}
map<int, int> mapp;



signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	eratos();
	mapp[0] = 0; mapp[1] = 0; mapp[2] = 1;


	while(tc--) {
		cin >> l >> r;
		cout << f(r) - f(l - 1);
	}
}