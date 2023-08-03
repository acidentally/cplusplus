#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define sc second
#define int ll
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
const int mod=1e9+7;
const int N=3e5+11;
int n, q, a[N], u, mp[N], ans;
vector<int> ned;
struct node
{
    node* child[2];
    node()
    {
        for(int i=0; i<2; i++) child[i]=NULL;
    }
};
node* root;
struct Trie
{
    Trie()
    {
        root = new node();
    }
    void add(int x)
    {
        node* pos = root;
        for (int i=29; i>=0; i--)
        {
            int c = (x>>i)&1;
            if (pos->child[c] == NULL) pos->child[c] = new node();
            pos = pos->child[c];
        }
    }
    int get(node* l, node* r, int d)
    {
        if (d < 0) return 0;
        if (!l || !r) return 1e18;
        if ((l->child[0] && r->child[0]) || (l->child[1] && r->child[1])) return min(get(l->child[0], r->child[0], d - 1), get(l->child[1], r->child[1], d - 1)); // neu bit(i, l)^bit(i, r) = 0 thi toi uu
        return min(get(l->child[0], r->child[1], d - 1), get(l->child[1], r->child[0], d - 1)) ^ (1<<d); // truong hop con lai
    }
    int calc(node *pos, int d)
    {
        if (pos == NULL) return 0;
        int ans = 0;
        ans += calc(pos->child[0], d - 1);
        ans += calc(pos->child[1], d - 1);
        if (pos->child[0] == NULL || pos->child[1] == NULL) return ans;
        return ans + get(pos->child[0], pos->child[1], d - 1) + (1<<d);
    }
};
Trie tri;
void sol()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        tri.add(a[i]);
    }
    cout << tri.calc(root, 29);
}
signed main()
{
//    freopen("divisor.INP", "r", stdin);
//    freopen("divisor.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
    {
        sol();
    }
}