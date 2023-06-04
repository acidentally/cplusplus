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
#define MOD 1000000007
int a[10001], F[10001][10];


int thu(int i, bool restricted, int sum) {
	if(i < 0) {
		if(sum == 0) return 1;
		else return 0;
	}
	bool newRestrict;
	if(!restricted && F[i][sum] >= 0) return F[i][sum];
	int kq = 0, maxCurr = (restricted) ? a[i] : 9;

	for(int j = 0; j <= maxCurr; j++) {
		newRestrict = restricted && (j == maxCurr);
		kq += thu(i - 1, newRestrict, (sum + j*j) % 3) % MOD;
	}
	if(!restricted) F[i][sum] = kq;
	return kq; 
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	string n; cin >> n;
	int d = 0;
	for(int i = 0; i < n.size(); i++) {
		if((n[i] - '0') % 3 != 0) d++;
		a[n.size() - i - 1] = n[i] - '0';
	}
	memset(F, -1, sizeof(F));
	cout << (thu(n.size() - 1, true, 0) - !(d % 3)) % MOD;
}