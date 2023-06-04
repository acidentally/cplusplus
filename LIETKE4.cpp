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

string s, s1 = "";
map<char, int> cha;
// char holder[16];
// bool check[16];
void start() {
	for(int i = 0; i < s.size(); i++) {
		cha[s[i]]++;
	}
	// sort(cha.begin(), cha.end());
}

void solve(int k) {
	if(s1.size() == s.size()) {
		cout << s1 << endl;
	} else {
		map<char, int>::iterator p;
		pair<char, int> q;
		
		for(p = cha.begin(); p != cha.end(); p++) {

			q = *p;
			if(q.se == 0) continue;
			else if(q.se > 0) {
				cha[q.fi]--;
				s1 = s1 + q.fi;
				solve(k + 1);
				cha[q.fi]++;
				s1.erase(s1.size() - 1, 1);
			} else if(q.se == 0) {
				continue;
			}
		}

	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> s;
	start();
	solve(1);
}