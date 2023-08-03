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




int cinn() {
	int n; cin >> n;
	return n;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	// freopen("FIB2.INP", "r", stdin);
	// freopen("FIB2.OUT", "w", stdout);
	int n, k, d;
	int tc; cin >> tc;
	string tempString, F1, F2;
	while(tc--) {
		cin >> n >> k;
		if(n == 0) cout << 1 << endl;
		else if(n == 1) cout << 0 << endl;
		else {
			F1 = "a", F2 = "b";
			n -= 1;
			while(n--) {
				tempString = F1 + F2;
				F1 = F2;
				F2 = tempString;
			}
			d = 0;
			for(int i = 0; i < k; i++) {
				if(tempString[i] == 'a') d++;
			} cout << d << endl;
		}		
	}
}