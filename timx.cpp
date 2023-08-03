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
map<int, int> idx;
vi a;
int n, x, cinTemp;
void solve() {
	cin >> n >> x;
	// a.push_back(-1);
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
		idx[cinTemp] = i + 1;
	}
	vi::iterator ptr1, ptr2, endptr, tempptr;
	ptr1 = a.begin();
	ptr2 = a.end(); ptr2--;
	int i;
	while(*ptr1 + *ptr2 != x && *ptr2 - *ptr1 > 0) {
		i = *ptr1 + *ptr2;
		if(i < x) {
			ptr1 = lower_bound(ptr1 + 1, ptr2, x - *ptr2);
		} else {
			ptr2 = lower_bound(ptr1, ptr2 - 1, x - *ptr1);
		}
	}
	if(*ptr1 + *ptr2 != x) cout << -1;
	else cout << idx[*ptr1] << ' ' << idx[*ptr2];
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}