#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 201000

ll par[sz];
ll rnk[sz];
ll add[sz];

ll getp(ll x)
{
	if (par[x] == x)
		return x;
	return getp(par[x]);
}

ll getpolls(ll x)
{
	if (par[x] == x)
		return add[x];
	return add[x] + getpolls(par[x]);
}

void uni(ll x, ll y)
{
	ll u = getp(x);
	ll v = getp(y);
	if (u == v)
		return;
	if (rnk[u] < rnk[v])
		swap(u, v);
	par[v] = u;
	add[v] -= add[u];
	if (rnk[u] == rnk[v])
		rnk[u]++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, q; cin >> n >> q;

	for (ll i = 1; i <= n; i++)
	{
		par[i] = i;
		rnk[i] = 1;
	}

	while (q--)
	{
		string s; cin >> s;
		if (s == "add")
		{
			ll a, b; cin >> a >> b;
			add[getp(a)] += b;
		}
		else if (s == "join")
		{
			ll a, b; cin >> a >> b;
			uni(a, b);
		}
		else
		{
			ll a; cin >> a;
			cout << getpolls(a) << "\n";
		}
	}

	return 0;
}