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
#define maxn 300010

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int n, ans = 0;
int luuhash[maxn], fachash[maxn], a[maxn], luuHashA[maxn];
void start() {
	mt19937_64 rng(time(NULL));
	for(int i = 1; i = n; i++) {
		luuhash[i] = rng();
		if(i > 0) fachash[i] = fachash[i - 1] ^ luuhash[i];
	}	
}
void enterArr() {
	cin >> a[0];
	luuHashA[0] = luuhash[a[0]];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		luuHashA[i] = luuHashA[i - 1] ^ luuhash[a[i]];
	}
}

void solve(int& pos) {
	int r = pos + 1;
	if(a[r] == 1) return;
	while(a[r] != 1) {
		if()
		r++;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	start(); enterArr();
	for(int i = 0; i < n; i++) {
		if(a[i] == 1) {
			solve(i);
			ans++;
		}
	}
	reverse(a, a + n);
	for(int i = 0; i < n; i++) {
		if(a[i] == 1) {
			solve(i);
		}
	}
	cout << ans;
}