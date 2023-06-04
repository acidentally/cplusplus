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

void swapi(int& a, int& b) {
	int k = a;
	a = b;
	b = k;
}

int sqr(int a) {
	return a * a;
}

int luythua(int a, int k) {
	if(k == 0) return 1;
	else if(a == 0) return 0;
	else {
		if(k % 2 == 0) {
			return sqr(luythua(a, k/2));
		} else {
			return a * sqr(luythua(a, k/2));
		}
	}
}

signed main() {
	int x, y;
	cin >> x >> y;
	cout << x <<' ' << y << endl;
	swap(x, y);
	cout << "Sau khi đổi chỗ: " << x << ' ' << y << endl;
	cout << luythua(x, y) << endl;
}

BTVN : 
+) PHần mảng : gồm
Câu 1 : Xuất, nhập mảng 1 chiều. Tìm số lớn nhất, nhỏ nhất trong mảng bằng cách viết hàm
Câu 2 : Tìm các số nguyên tố có trong mảng bằng cách viết hàm ktra số nguyên tố
Câu 3 : Sắp xếp mảng theo thứ tự tăng dần (câu nâng cao)
+) Nhập vào n bán kính bánh xe, mỗi bánh xe bán kính khác nhau, và được liên kết liên tục
với nhau theo thứ tự nhập vào. Hỏi băng xe thứ nhất quay 1 vòng thì bánh xe cuối quay mấy vòng. 
Bỏ qua ma sát. Số vòng quay tính bằng tỉ lệ bán kính.
+) Viết cách nhập xâu, xuất xâu, ktra xem xâu có độ dài bao nhiêu, xâu đối xứng và các
hàm xử lí xâu

s.size()
s.empty()
s.at 
s.resize()
s.insert()
s.erase
s.substr
s.clear()
