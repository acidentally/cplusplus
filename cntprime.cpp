#include<bits/stdc++.h>
using namespace std;
const int nmax=2000011, base=1000000007;
typedef long long ll;

int gt[nmax],ndgt[nmax],n,m,k,f[1111];
pair<int,int> a[1111];

ll pp(ll a,ll n){
    ll r=1;
    while(n){
        if (n&1) r=r*a%base;
        a=a*a%base;
        n>>=1;
    }
    return r;
}

ll c(int k,int n){
    return 1LL*gt[n]*ndgt[k]%base*ndgt[n-k]%base;
}

int32_t main(int32_t argc,char** argv){
    // if (argc>2){
    //     freopen(argv[1],"r",stdin);
    //     freopen(argv[2],"w",stdout);
    // }
    gt[0]=ndgt[0]=1;
    for (int i=1;i<nmax;++i) gt[i]=ll(gt[i-1])*i%base;

    ndgt[nmax-1]=pp(gt[nmax-1],base-2);

    for (int i=nmax-2;i;--i) ndgt[i]=ndgt[i+1]*(i+1LL)%base;

    cin>>n>>m>>k;

    for (int i=0;i<k;++i) cin>>a[i].first>>a[i].second;

    a[k++]=make_pair(1,1);
    a[k++]=make_pair(n,m);

    sort(a,a+k);
    f[0]=1;
    
    for (int i=1;i<k;++i){
        int x=a[i].first, y=a[i].second;
        f[i]=c(x-1,x+y-2);
        for (int j=1;j<i;++j) {
            if (a[j].first<=x&&a[j].second<=y) {
                f[i]=(f[i]+base-(f[j]*c(x-a[j].first,x-a[j].first+y-a[j].second)%base))%base;
            }
        }
    }
    cout<<f[k-1];
    return 0;
}
