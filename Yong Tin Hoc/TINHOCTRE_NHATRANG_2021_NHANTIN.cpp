#include <bits/stdc++.h>
using namespace std;

#define int long long
int seconds[26];
int nhom[26];

void start() {
	int d = 0, cnt = 1, temp = 0;
	for(int i = 'a'; i <= 'z'; i++) {
		if((i - 'z' - temp) % 3 == 0) cnt++;
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
	if(s[0] != '1' || s[0] != '.' || s[0] != ',' || s[0] != '?' || s[0] != '!') sec++;
	for(int i = 0; i < s.size(); i++) {

		if(s[i] <= '9' && s[i] >= 0) {
			sec += 4; 
			if(s[i] == '0') {
				sec -= 2;
			}
			else if(s[i] == '7' || s[i] == '9' || s[i] == '1') {
				sec++;
			} 
			continue;
		}
		if(s[i] == '.') {sec += 1; continue;}
		if(s[i] == ',') {sec += 2; continue;}
		if(s[i] == '?') {sec += 3; continue;}
		if(s[i] == '!') {sec += 4; continue;}
		if(s[i] == '_') {sec += 1; continue;}
		sec += seconds[s[i] - 'a'];
	}	
	cout << sec << endl;
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