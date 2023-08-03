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
int cinTemp;

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	stack<int> a;
	cin >> cinTemp; a.push(cinTemp);
	int res = 0, cur = 0;

	for(int i = 0; i < n - 1; i++) {
		
		cin >> cinTemp;
		if(cinTemp > a.top()) {
			while(!a.empty() && cinTemp > a.top()) {
				res++;
				a.pop();
			}
			if(!a.empty()) {
				if(cinTemp == a.top()) cur++;
				else cur = 0;
				res += cur;
				res += (a.size() > cur) ? 1 : 0;
			}
			a.push(cinTemp);
		}
		else if(cinTemp < a.top()) {
			a.push(cinTemp); res++;
		}
		else if(cinTemp == a.top()) {
			cur++;
			res += cur;
			res += (a.size() > cur) ? 1 : 0;
			a.push(cinTemp);
		}
	}
	cout << res;
}