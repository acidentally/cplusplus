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
#define pi pair<int, int>


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

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, x; cin >> n;
	multiset<int> a;
	int ans = 0;
	for(int i = 0; i < 2 * n; i++) {
		cin >> x;
		a.insert(x);
	}
	queue<pi> q;
	multiset<int>::reverse_iterator ptr1 = a.rbegin(), ptr2 = a.rbegin();
	ptr2++;
	while(ptr2 != a.rend()) {
		ans += *ptr1 * *ptr2;
		q.push({*ptr2, *ptr1});
		ptr1++; ptr1++;
		ptr2++; 
		if(ptr2 == a.rend()) break;
		ptr2++;
	}
	cout << ans << endl;
	while(!q.empty()) {
		cout << q.front().fi << ' ' << q.front().se << endl;
		q.pop();
	}
}