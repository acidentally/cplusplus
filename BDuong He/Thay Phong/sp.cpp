#include <bits/stdc++.h>
using namespace std;
#define long long long
#define ll pair<long, long>
#define st first
#define nd second
const long N = 2e5 + 10;
const long oo = 1e18;
long n, A[N], m, k, x, y, c, B[N], D[N], F[N], sz, F2[N];
ll u;
vector<ll> ds[N];
long vs[N];
vector<long> dinh;
bool vst[N];
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<long> ans;
void dij(long a)
{
    while (!pq.empty())
        pq.pop();
    for (long i = 1; i <= n; i++)
        F[i] = oo;
    pq.push({0, a});
    F[a] = 0;
    while (!pq.empty())
    {
        u = pq.top();
        pq.pop();
        if (F[u.nd] != u.st)
            continue;
        for (ll v : ds[u.nd])
        {
            if (F[v.nd] > v.st + u.st)
            {
                F[v.nd] = v.st + u.st;
                pq.push({F[v.nd], v.nd});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (long i = 1; i <= k; i++)
    {
        cin >> B[i];
        D[B[i]] = true;
    }
    for (long i = 1; i <= m; i++)
    {
        cin >> x >> y >> c;
        ds[x].push_back({c, y});
        ds[y].push_back({c, x});
    }
    if (k == 1)
    {
        cout << n << '\n';
        for (long i = 1; i <= n; i++)
        {
            cout << i << ' ';
        }
        return 0;
    }
    dij(B[1]);
    x = 0;
    F[0] = 0;
    for (long i = 1; i <= n; i++)
    {
        if (D[i] && F[i] > F[x])
        {
            x = i;
        }
    }
    dij(x);
    for (long i = 1; i <= n; i++)
        F2[i] = F[i];
    y = 0;
    for (long i = 1; i <= n; i++)
    {
        if (D[i] && F[i] > F[y])
        {
            y = i;
            sz = F[i];
        }
    }
    dij(y);
    for (long i = 1; i <= n; i++)
    {
        if (F2[i] + sz == F[i] || sz + F[i] == F2[i])
        {
            ans.push_back(i);
        }
        if (D[i] && F2[i] + F[i] != sz)
        {
            ans.clear();
            break;
        }
    }
    cout << ans.size() << '\n';
    for (long v : ans)
        cout << v << ' ';
    return 0;
}
