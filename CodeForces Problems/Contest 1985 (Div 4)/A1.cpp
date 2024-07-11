#include<bits/stdc++.h> 
using namespace std;
#define int long long
 
void solve(){
    int n,m;
    cin >> n >> m;
    char x[n+1][m+1];
    bool check = false;
    int tmp1 = 0, tmp2 = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> x[i][j];
            if(x[i][j]=='#' && check == false){
                tmp1 = i;
                tmp2 = j;
                check = true;
            }
        }
    }
    int tmp3=tmp1;
    while(x[tmp1][tmp2] == '#'){
        tmp1 ++;
    }
    tmp1--;
    cout << (tmp1+tmp3)/2 << " " << tmp2;
 
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}