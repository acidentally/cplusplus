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
void swapi(char &a, char& b) {
	char k = b;
	b = a;
	a = k;
}
int p[4] = {2, 3, 5, 7};
void solve(int n) {
	map<int, int> mapp;
	for(int i = 0; i < 4; i++) {
		while(n % p[i] == 0) {
			n /= p[i];
			mapp[p[i]]++;
		}
	}
	if(n > 10) {
		cout << -1;
		return;
	} 
	string s = "";
	map<int, int>::iterator ptr = mapp.begin();
	while(ptr != mapp.end()) {
		while(ptr -> second > 0) {
			ptr -> second --;
			s = s + char(ptr -> fi + 48);
		}
		ptr++;
	}
	cout << s << endl;
	int idx = s.size() - 1;
	while(idx > 0) {
		if((s[idx] - '0') * (s[idx - 1] - '0') < 10) {
			s[idx - 1] = (s[idx - 1] - '0') * (s[idx] - '0') + '0';
			s.erase(idx, 1);
		}
		idx--;
		// if(s[idx] > s[idx + 1]) swapi(s[idx], s[idx - 1]);
	}
	cout << s;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int x; cin >> x;
	if(x == 0) {
		cout << 10;
		return 0;
	} else if(x < 10) {
		cout << x;
		return 0;
	}
	solve(x);
}


