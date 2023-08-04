#pragma GCC optimize("Os")
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
#define maxx (int)(1e9)
string F[110][110] ;
int tonum(string a) {
	int ans = 0;
	for(int i = 0; i < a.size(); i++) {
		ans = ans * 10 + a[i] - '0';
	} return ans;}
string tostring(int a) {
	string ans = "";
	if(a == 0) return "0";
	else {
		while(a) {
			ans = (char)(a % 10 + '0') + ans;
			a /= 10;
		}
	} return ans;}
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
	return res;}
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
	return res;}
string multi(string a, string b) {
	string res = "0";
	string save[10];
	save[1] = a;
	fr(i,2,10) {
		save[i] = sum(save[i - 1], a);}
	string temp = "";
	for(int i = b.size() - 1; i >= 0; i--) {
		if(b[i] == '0') temp = temp + '0';
		else {
			res = sum(res, save[b[i] - '0'] + temp);
			temp = temp + '0';
		}
	} while(res[0] == '0' && res.size() > 1) res.erase(0, 1);
	return res;}	
string maxmize(string a, string b) {
	if(a.size() > b.size()) return a;
	else if(a.size() < b.size()) return b;
	else {
		for(int i = 0; i < a.size(); i++) {
			if(a[i] > b[i]) return a;
			else if(a[i] < b[i]) return b;
		}
	}}
void divide(string n, string m) {
	int a = tonum(n), b = tonum(m);
	if(F[a][b] == "0") {
		if(b == a || b == 1) F[a][b] = "1";
		else {
			divide(minuss(n, "1"), m);
			divide(minuss(n, "1"), minuss(m, "1"));
			F[a][b] = sum(multi(F[a - 1][b], m), F[a - 1][b - 1]);
			return;
		}
	} }
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	fr(i,0,101) {
		fr(j,0,101) F[i][j] = "0";
	}
	string maxi = "0", n, m;
	cin >> n >> m;
	int a = tonum(n), b = tonum(m);
	divide(n, m); 
	cout << F[a][b] << endl;

	for(int i = a - 1; i > 1; i--) {
		divide(n, tostring(i));
		maxi = maxmize(maxi, F[a][i]);
	}
	cout << maxi;}