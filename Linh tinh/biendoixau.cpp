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

int n, m, x;
map<int, int> a, b, c;	
map<int, int> mapp;
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> x;
		mapp[x] = i;
	} //mapp
	for(int i = 1; i <= m; i++) {
		cin >> x;
		a[i] = x;
	} //a
	for(int i = 1; i <= m; i++) {
		cin >> x;
		b[i] = x;
	} //b
	for(int i = 1; i <= m; i++) {
		cin >> x;
		c[i] = x;
	} //c

	map<int, int>::iterator ptr1 = mapp.begin(), ptr2 = mapp.begin(), ptr3 = mapp.begin();
	ptr1++;
	int ans = 0;
	int typea, typeb, typec, k;
	while(ptr1 != mapp.end() && ptr2 != mapp.end() && ptr3 != mapp.end()) {
		while(ptr1 != mapp.end() && a[ptr1 -> se] == 0) ptr1++; 
		while(ptr2 != mapp.end() && b[ptr2 -> se] == 0) ptr2++;
		while(ptr3 != mapp.end() && c[ptr3 -> se] == 0) ptr3++;
		while(ptr1 != mapp.end() && ptr1 -> fi == min(ptr2 -> fi, ptr3 -> fi)) ptr1++;
		if(ptr1 == mapp.end() || ptr2 == mapp.end() || ptr3 == mapp.end()) break;



		typea = ptr1 -> se;	typeb = ptr2 -> se; typec = ptr3 -> se;
		k = min(a[typea], min(b[typeb], c[typec]));
		ans += k;
		a[typea] -= k;
		b[typeb] -= k;
		c[typec] -= k;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}