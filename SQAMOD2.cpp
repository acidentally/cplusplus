#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int s[3]={0}, s2[3]={0}, p=0, x;
	string st;
	cin >> st;
	for(int i=0; i<st.size(); i++){
		x=st[i]-48;
		for(int j=0; j<3; j++){
			s2[(p+j)%3]=4*s[(p+j)%3]+6*s[(p+j+2)%3]+(x+2-j)/3;
		}
		for(int j=0; j<3; j++){
			s[j]=s2[j]%MOD;
		}
		p=(p+x)%3;
	}
	cout<<s[0];
}