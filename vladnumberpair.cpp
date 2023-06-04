#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t, n, x, d, dp, s;
	multiset<int> a;
	multiset<int> ::iterator it;
	cin>>t;
	for(int i=0; i<t; i++){
		a=multiset<int> ();
		cin>>n;
		for(int j=0; j<n; j++){
			cin>>x;
			a.insert(x);
		}
		a.insert(1e9+1);
		d=dp=x=s=0;
		for(it=a.begin(); it!=a.end(); it++){
			if(*it!=x){
				s+=max(0, d-dp);
				if(*it==x+1){
					dp=d; x=*it; d=1;
				}
				else{
					dp=0; x=*it; d=1;
				}
			}
			else{
				d++;
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}