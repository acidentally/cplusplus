/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define mod 1058375681

int const rvMod = 985416512;

int sqr(int a) {
	return a * a;
}
int sqrmod(int n) {
	if(n == 0) return 1;
	if(n == 1) return 2;
	if(n % 2 == 0) return sqr(sqrmod(n/2)) % mod;
	else return 2 * sqr(sqrmod(n/2)) % mod;
}
int f(int n) {
	if(n % 2 == 0) {
		return (sqrmod(n) - 1) * rvMod % mod;
	} else return (sqrmod(n) + 1) * rvMod % mod;	
}

int rvmod(int a, int k) {
	if(k == 1) return a;
	if(k == 0) return 1;
	if(k % 2 == 0) {
		return sqr(rvmod(a, k/2)) % mod;
	}
	else return a * sqr(rvmod(a, k/2)) % mod;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << rvmod(f(6), 1058375681);
}