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
// #define mod 100003
const int mod = 100003;
int sqr(int x) {
	return (x * x) % mod;
}

int Combinatorics(int k, int n) {
	
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	int m, n, k;
	while(tc--) {
		cin >> m >> n >> k;
		if(m/n >= k) cout << Com(n - 1, m - n * k + n - 1) << endl;
		else cout << 0 << endl;
	}
}

//nCk = n! / k! / (n - k)!