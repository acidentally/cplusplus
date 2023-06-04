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
#define maxn (int)1e6 + 10

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

vector<bool> isPrime(maxn, 0);

void eratos() {

	// isPrime[2] = isPrime[3] = true;
	for(int i = 0; i < maxn; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i < maxn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j < maxn; j += i) {
				isPrime[j] = false;
			}
		}
	}
}
int cinTemp;

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	eratos();
	while(tc--) {
		cin >> cinTemp;
		if(isPrime[cinTemp]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}