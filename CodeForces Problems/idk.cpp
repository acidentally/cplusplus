#include<bits/stdc++.h> 
using namespace std;
#define int long long
const long long mod = 1e9+7;




void solve(){
    int n,k;
    cin >> n >> k;
    if(k%2==1) cout << "No";
    else if((n%2==0 && k>n*n/2) || (n%2==1 && k>(n-1)*(n+1)/2)) cout << "No";
    else{
        cout << "Yes" << endl;
        k/=2; //cout << k << endl;
        int a[n+1];
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
        //1 2 3 4 5 6 7 8
        int t = 0;
        while(k>1){
            int j = n-1;
            j-=2*t;
            t++;
            if(k>=j){
                k-=j;
                //cout << t << endl;
                swap(a[t],a[n-t+1]);
            }  
        }
        //cout << t << endl;
        if(k==1) swap(a[(n+1)/2],a[(n+1)/2+1]);

        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}