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
#define maxn 100000

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int cinn() {
	int n; cin >> n;
	return n;
}
vi a; int n;
vi StartOf(maxn + 10), Len[maxn + 10], Trace[maxn + 10];

void BinarySearch(int l, int r, int& k, int idx) {
	if(l == r) {
		k = l; return;
	} else {
		int mid = (l + r) / 2;
		if(a[StartOf[mid]] > a[idx]) {
			BinarySearch(mid + 1, r, k, idx);
		} else {
			BinarySearch(l, mid, k, idx)
		}
	}
}	

void solve(vi a) {
	memset(StartOf, n - 1, sizeof(StartOf));
	memset(Len, 1, sizeof(Len));
	int maxLen = 1, k, currSize;
	for(int i = n - 2; i >= 0; i--) {
		BinarySearch(1, n, k, i);
		//tìm chỉ số k lớn nhất (k == size của dãy con tăng) rồi gán k + 1
		// sao cho a[StartOf[k]] > a[i];
		currSize = k + 1;
		if(currSize > m) { 
			m++;
			StartOf[m] = i;
			Len[i] = m;
		} else {
			Len[i] = currSize;
			if(a[StartOf[k]] < a[i]) StartOf[k] = i;
		}
		Trace[i] = currSize;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	fr(i,0,n) {
		a.push_back(cinn());
	}
	solve(a);
}