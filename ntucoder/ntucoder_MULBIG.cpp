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
#define mp(a,b) make_pair(a, b)

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
map<string, bool> sqrCheck;
map<string, string> sqrLuu;
map<pair<string, string>, bool> mulCheck;
map<pair<string, string>, string> mulLuu;

string sum(string a, string b) {
	string res = "";
	int rem = 0;
	int temp;
	while(a.size() < b.size()) {
		a = '0' + a;
	}
	while(b.size() < a.size()) {
		b = '0' + b;
	}
	// cout << a << b;

	int cur = a.size() - 1;
	while(cur > -1) {
		temp = a[cur] + b[cur] - 2*'0' + rem;
		if(temp <= 9) {
			res = (char)(temp + '0') + res;
			rem = 0;
		} else {
			temp -= 10;
			res = (char)(temp +'0') + res;
			rem = 1;			
		}

		cur--;
	}
	if(rem == 1) {
		res = (char)(1 +'0') + res;
	}
	while(res[0] == '0' && res.size() > 1) {
		res.erase(0,1);
	}
	// cout << res << endl;
	return res;
}
string minuss(string a, string b) {
	string res = "";
	int temp = 0;
	int rem = 0;

	char tempChar = '+';
	while(a.size() < b.size()) {
		a = '0' + a;
	}
	while(b.size() < a.size()) {
		b = '0' + b;
	}

	int cur = b.size() - 1;

	bool check = false;
	int i;
	for(i = 0; i <= cur; i++) {
		if(a[i] < b[i]) {
			check = false; break;
		} else if(a[i] > b[i]) {
			check = true; break;
		} else {
			continue;
		}
	}
	if(i > cur) {
		return "0";
	}

	if(!check) {
		tempChar = '-';
		// cout << '-';
		swap(a,b);
	}

	while(cur > -1) {
		temp = a[cur] - b[cur] - rem;
		// cout << temp << endl;
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
	while(res[0] == '0' && res.size() > 1) {
		res.erase(0, 1);
	}
	if(tempChar == '-') res = tempChar + res;
	// cout << res << endl;
	return res;
}
string multi(string a, string b) {
	string res = "0";
	string save[10];
	// save[0] = "0";
	save[1] = a;
	fr(i,2,10) {
		save[i] = sum(save[i - 1], a);
	}
	string temp = "";
	for(int i = b.size() - 1; i >= 0; i--) {
		if(b[i] == '0') {
			temp = temp + '0';
		} else {
			res = sum(res, save[b[i] - '0'] + temp);
			temp = temp + '0';
		}
	}
	while(res[0] == '0' && res.size() > 1) {
		res.erase(0, 1);
	}
	return res;
}
string sqr(string a) {
	if(sqrCheck[a]) return sqrLuu[a];
	string res = "0", b = a;
	string save[10];
	// save[0] = "0";
	save[1] = a;
	fr(i,2,10) {
		save[i] = sum(save[i - 1], a);
	}
	string temp = "";
	for(int i = b.size() - 1; i >= 0; i--) {
		if(b[i] == '0') {
			temp = temp + '0';
		} else {
			res = sum(res, save[b[i] - '0'] + temp);
			temp = temp + '0';
		}
	}
	while(res[0] == '0' && res.size() > 1) {
		res.erase(0, 1);
	}
	sqrCheck[a] = true;
	sqrLuu[a] = res;
	return res;
}		
string div2(string a) {
	// if(div2Check[a]) return div2Luu[a];
	if(a[a.size() - 1] % 2 == 1) {
		a[a.size() - 1] -= 1;
	}
	int rem = 0;
	string ans = "";
	for(int i = 0; i < a.size(); i++) {
		ans = ans + char((a[i] - 48 + 10*rem) / 2 + 48);
		if(a[i] % 2 == 1) rem = 1;	
		else rem = 0;
	}
	while(ans[0] == '0') ans.erase(0, 1);
	// div2Check[ans] = true;
	// div2Luu[a] = ans;
	return ans;
}
string mul(string a, string b) {
	if(mulCheck[mp(a,b)]) return mulLuu[mp(a,b)];
	if(b == "0") return "1";
	else if(b == "1") return a;
	else {
		if(b[b.size() - 1] % 2 == 1) {
			string ans = sqr(mul(a, div2(b)));
			mulCheck[mp(a,b)] = true;
			mulLuu[mp(a,b)] = multi(a, ans);
			return mulLuu[mp(a,b)];
		}
		else {
			mulLuu[mp(a,b)] = sqr(mul(a, div2(b)));
			mulCheck[mp(a,b)] = true;
			return mulLuu[mp(a,b)];
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	string a, b; cin >> a >> b;
	if(a == b) {
		cout << "0";
		return 0;
	}
	cout << minuss(mul(a, b), mul(b, a));
}