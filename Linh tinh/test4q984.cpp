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

int cinn() {
	int n; cin >> n;
	return n;
}
//Cho 2 xâu s1, s2 gồm các chữ cái hoa thường và kí tự trắng
//trong mỗi xâu có ít nhất 1 chữ cái, 1 xâu có ko quá 100 kí tự
//1) Nhập xâu
//Nếu chiều dài xâu s1 lớn hơn chiều dài xâu s2 thì in s1 > s2
//nếu bằng in s1=s2, khác thì s1 < s2
//tạo xâu s3 gồm các kí tự chữ cái trong s1, sau đó xuất ra màn hình
// đếm số lượng từ trong xâu s1, biết rằng từ là 1 hoặc nhiều chữ cái kề nhau được ngăn cách
//bằng một dấu cách

signed main() {
	string s1, s2; 
	getline(cin, s1); getline(cin, s2);

	if(s1.size() > s2.size()) cout << "s1 > s2" << endl;
	else if(s1.size() == s2.size()) cout << "s1 = s2" << endl;
	else cout << "s1 < s2" << endl;
	
	string s3 = "";

	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] >= 'a' && s1[i] <= 'z' || s1[i] >= 'A' && s1[i] <= 'Z') {
			s3 = s3 + s1[i];
		}
	} cout << s3 << endl;

	int tu = 0;
	// cout << s1;
	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] >= 'a' && s1[i] <= 'z' || s1[i] >= 'A' && s1[i] <= 'Z') {
			tu++;
			while(s1[i] != ' ') i++;
		}
	} cout << tu;
}