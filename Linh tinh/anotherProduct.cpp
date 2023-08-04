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

multiset<int> neg, pos;
int cinTemp;
vi a;

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		if(cinTemp < 0) neg.insert(-cinTemp);
		else pos.insert(cinTemp);
		a.push_back(cinTemp);
	}
	multiset<int>::iterator ptr1, ptr2;
	if(n == 2) {
		cout << a[0] * a[1]; return 0;
	} else if(pos.size() == 0) {
		ptr1 = neg.end(); ptr1--; ptr1--;
		ptr2 = neg.end(); ptr2--;
		cout << *ptr1 * *ptr2;
	} else if(neg.size() == 0) {
		ptr1 = pos.end(); ptr1--; ptr1--;
		ptr2 = pos.end(); ptr2--;
		cout << *ptr1 * *ptr2;
	}
	else {
		if(pos.size() >= 2 && neg.size() == 1) {
			ptr1 = pos.end();
			ptr1--; ptr1--;
			ptr2 = pos.end(); ptr2--;

			cout << *ptr1 * *ptr2;
		}
		else if(neg.size() >= 2 && pos.size() == 1) {
			ptr1 = neg.end();
			ptr1--; ptr1--;
			ptr2 = neg.end(); ptr2--;
			cout << *ptr1 * *ptr2;
		} else if(pos.size() >= 2 && neg.size() >= 2) {
			ptr1 = neg.end(); ptr1--; ptr1--;
			ptr2 = neg.end(); ptr2--;
			int maxi = *ptr1 * *ptr2;
			ptr1 = pos.end(); ptr1--; ptr1--;
			ptr2 = pos.end(); ptr2--;
			maxi = max(maxi, *ptr1 * *ptr2);
			cout << maxi;
		}
	}
}