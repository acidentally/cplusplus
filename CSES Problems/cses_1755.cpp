/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int cnt[28] = {};
char x;
void solve() {
	while(cin >> x) {
		cnt[x - 'A']++;
	}
	int temp = 0;
	char midChar;
	bool isMid = false;
	for(int i = 0; i < 26 && temp <= 1; i++) {
		if(cnt[i] & 1) {
			midChar = (char)i + 'A';
			isMid = true;
			temp++;
		}
		cnt[i] /= 2;
	}
	if(temp > 1) {
		cout << "NO SOLUTION";
		return;
	}
	for(int i = 0; i < 26; i++) {
		if(!cnt[i]) continue;
		else {
			for(int j = 0; j < cnt[i]; j++) {
				cout << char(i + 'A');
			}
		}
	}
	if(isMid) cout << midChar;
	for(int i = 25; i >= 0; i--) {
		if(!cnt[i]) continue;
		else {
			for(int j = 0; j < cnt[i]; j++) {
				cout << char(i + 'A');
			}
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}