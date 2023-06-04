/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
	
int t1, s1, t2, s2;
void solve() {
	//1 : megumin ; 2 : yunyun
	cin >> t1 >> s1 >> t2 >> s2;
	int len1 = 0, len2 = 0;
	int allBack1 = 10, allBack2 = 10;
	while(true) {
		len1 += t1 + min(s1, allBack1); len2 += t2 + min(s2, allBack2);
		allBack1 = max(0ll, allBack1 - s1);
		allBack2 = max(0ll, allBack2 - s2);
		if(len1 >= 100 && len1 > len2) {
			cout << "Megumin" << endl;
			break;
		}
		else if(len2 >= 100 && len2 > len1) {
			cout << "Yunyun" << endl;
			break;
		}
		else if(len1 >= 100 && len1 == len2) {cout << "Draw" << endl; break;}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}