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
vi begin;

void binarySearch(int k, int l, int r) {
	if(l == r) {
		if(a[begin[l]] != a[k]) {
			b[k] = b[begin[l]] + 1;
		}
		else {
			b[l] = begin[l];
		}
	}
	int mid = (l + r) / 2;
	if(begin[mid] < k) {
		r = mid;
		binarySearch(k, l, r);
	} else if(begin[mid] > k) {
		l = mid + 1;
		binarySearch(k, l, r);
	}

}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n; cin >> n;
	int a[n], b[n] = {}, trace[n]; //begin[i] là mảng lưu chỉ số j sao cho a[j] lớn nhất
	//mà tại đó là bắt đầu của một dãy con tăng có độ dài i
	// => begin[1] > begin[2] > begin[3] ...
	// hay đơn giản là begin là nghịch biến
	// sau mỗi bước chỉ cần tìm j lớn nhất sao cho begin[j] > i
	trace[n - 1] = -1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		begin.push_back(n - 1);
	}
	begin.push_back(n - 1);	

	b[n - 1] = 1;
	begin[0] = n;

	for(int i = n - 2; i >= 0; i--) {
		for(j = i + 1; j < n; j++) {
			maxi = max(b[j] && a[j] > a[i]);
			b[i] = b[j] + 1;
			//vòng này chạy trong O(n^2);
			//nlogn -> logn là tìm begin[i];
			//
		}

		binarySearch(i, 0, n - i - 1);
	}	

}
