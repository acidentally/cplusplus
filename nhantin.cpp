#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int seconds[26];
int nhom[30];

void start() {
	int d = 0, cnt = 1, temp = 0;
	nhom[26] = 1; nhom[27] = 1; nhom[28] = 1; nhom[29] = 1;
	for(int i = 'a'; i <= 'z'; i++) {
		if((i - 'a' - temp) % 3 == 0) cnt++;
		if(i == 's' || i == 'z') {
			d--;
			temp++; cnt--;
			nhom[i - 'a'] = cnt;
			seconds[i - 'a'] = 4; continue;
		}
		seconds[i - 'a'] = 1 + (i - 'a' + d) % 3;
		nhom[i - 'a'] = cnt;
	}
}

void solve(string s){
	int sec = s.size() - 1;
	for(int i = 0; i < s.size(); i++) {
		if(i > 0)
		if(s[i] <= '9' && s[i] >= 0) {
			sec += 4;
			if(s[i] == '1' || s[i] == '7' || s[i] == '9') sec++;
			else if(s[i] == '0') sec -= 2;
			continue;
		} else if(s[i] <= 'z' && s[i] >= 'a') {
			sec += seconds[s[i] - 'a'];
		} else {
			switch(s[i]) {
			case '.' : sec += 1;
			case ',' : sec += 2;
			case '?' : sec += 3;
			case '!' : sec += 4;
			}
		}
	}	cout << sec << endl;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	start();
	int tc; cin >> tc;
	string s;
	while(tc--) {
		cin >> s;
		solve(s);
	}
	// solve(s);
}