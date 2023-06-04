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
int cinTemp;

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, k; cin >> n >> k;
	multiset<int> h;
	fr(i,0,n) {
		h.insert(cinn());
	}
	multiset<int>::iterator ptr1 = h.begin(), ptr2 = h.begin();
	int cnt = 0;
	while(ptr2 != h.end()) {
		if(*ptr2 - *ptr1 > k) {
			ptr1++;
		} else if(*ptr2 - *ptr1 < k) {
			ptr2++;
		} else if(*ptr2 - *ptr1 == k) {
			cnt++;
			ptr1++;
			ptr2++;
		}
	}
	cout << cnt;

}