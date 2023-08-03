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

int n;
map<int, string> mapp;
void init() {
	mapp[0] = "a";
	mapp[1] = "I";
	mapp[4] = "IV";
	mapp[5] = "V";
	mapp[9] = "IX";
	mapp[10] = "X";
	mapp[40] = "XL";
	mapp[50] = "L";
	mapp[90] = "XC";
	mapp[100] = "C";
}
void solve() {
	cin >> n;
	string s;
	map<int, string>::iterator ptr = mapp.end();
	ptr--;
	while(ptr->fi != 0) {
		if(ptr -> fi <= n) {
			n -= ptr -> fi;
			s += ptr -> se;
		}
		else ptr--;
	}
	cout << s;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	init();
	solve();
}