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
int res;
int cinn() {
	int n; cin >> n;
	return n;
}
 
void speceil(int& a, int b) {
	res += 1;
	if(a % b == 0) a = a/b;
	else a = a/b + 1;
}
 
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	// int cinTemp;
	int n;
	// vi num;
	multiset<int> a;
	set<int> check;
	int minmin, minpos;
 
	vector< pair<int, int> > results;
	while(tc--) {
		cin >> n;
		results = vector< pair<int, int> >();
		check = set<int>();
		int num[n];
		minmin = 1e18;
 
		fr(i,0,n) {
			cin >> num[i];
			check.insert(num[i]);
			if(num[i] < minmin) {
				minpos = i;
				minmin = num[i];
			}
		}
 
		res = 0;
		bool lak = false;
		int tempmin, tempmax;
		if(check.size() == 1) {
			cout << 0 << endl;
		} else if(*check.begin() == 1) {
			cout << -1 << endl;
		} else {	
			for(int i = 0; i < n; i++) {
				if(i == minpos) continue;
				while(num[i] > minmin && num[i] != 2) {
					results.push_back(make_pair(i, minpos));
					speceil(num[i], minmin);
				}
				if(num[i] < minmin) {
					minpos = i;
					minmin = num[i];
					i = -1;
				}
				else if(num[i] == 2 && !lak) {
					minpos = i;
					minmin = 2;
					lak = true;
					i = -1;
				}
			}
			cout << res << endl;
			for(int i = 0; i < results.size(); i++) {
				cout << results[i].fi + 1 << ' ' << results[i].se + 1<< endl;
			}
		}
	}
}