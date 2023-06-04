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


const int mod = 111539786;


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n;
	while(cin >> n) {
		n++;
		int a = n, b = n + 1, c = a + b;
		if(a % 3 == 0) a /= 3;
		else if(b % 3 == 0) b /= 3;
		else c /= 3;
		int ans = ((((((2 * a) % mod) * b) % mod) * c) % mod - (((4*n) % mod) * n % mod) + 2*n - 1) % mod;
		cout << ((ans < 0) ? (ans + mod) % mod : ans % mod) << endl;
	}
}
// n^2 - 2n + 1 + 3n^2