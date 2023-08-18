#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair <int,int>
#define sz(a) (int)(a.size())

vector < vector < int > > a;
int res,n,h[200005];

void dfs (int u, int pre)
{
    int nchild = 0; int v1=0,v2=0;
    h[u]=1;
    for (int i=0;i<sz(a[u]);i++)
    {
        int v = a[u][i];
        if (v==pre) continue;
        dfs(v,u);
        nchild++;
        if (nchild==1) v1 = v;
        if (nchild==2) v2 = v;
    }
    h[u] = max(h[v1],h[v2])+1;
    if (abs(h[v1]-h[v2])>1)
    {
        if (h[v1]>h[v2]) h[v1] = h[v2]+1;
        else h[v2] = h[v1]+1;
    }
    h[u] = max(h[v1],h[v2])+1;
}

void dfs2 (int u, int pre)
{
    if (h[u]<1) res++;
    for (int i=0;i<sz(a[u]);i++)
    {
        int v = a[u][i];
        if (v==pre) continue;
        h[v] = min(h[v],h[u]-1);
        dfs2(v,u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a.resize(n+1);
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs (1,0);
    dfs2(1,0);
    cout<<res;
    return 0;
}
 