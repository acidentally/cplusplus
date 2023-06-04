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

void minuss(string a, string b) {
	string res = "";
	int temp = 0;
	int rem = 0;

	char tempChar;
	while(a.size() < b.size()) {
		a = '0' + a;
	}
	while(b.size() < a.size()) {
		b = '0' + b;
	}

	int cur = b.size() - 1;

	int check = 0;
	int i;
	for(i = 0; i < cur; i++) {
		if(a[i] < b[i]) {
			check = -1; break;
		} else if(a[i] > b[i]) {
			check = 1; break;
		}
	}
	if(i == cur) {
		// return "0";
	}

	if(check == -1) {
		tempChar = '-';
		cout << '-';
		swap(a,b);
	}

	while(cur > -1) {
		temp = a[cur] - b[cur] - rem;
		if(temp < 0) {
			rem = 1;
			temp += 10;
			res = char(temp + '0') + res;
		} else {
			rem = 0;
			res = char(temp + '0') + res;
		}



		cur--;
	}
	while(res[0] == '0') {
		res.erase(0, 0);
	}
	if(tempChar == '-') res = tempChar + res;
	cout << res << endl;
	// return res;

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	string a, b;
	cin >> a >> b;
	minuss(a,b);
}