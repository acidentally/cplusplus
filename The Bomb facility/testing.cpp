/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1745.cpp
Code by : acident / lckintrovert
Created since : 06/08/2023 ~~ 20:42:09
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned long long
#define dub double
#define fi first
#define se second
#define vvi vector<vector<int>>
#define endl '\n'
#define pb emplace_back
#define pf push_front
#define mp make_pair
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define ins insert

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
int const maxn = 2e5 + 10;

int n, a[110] = {};
bool check[maxn] = {};
vi all;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    all.pb(a[0]);
    check[a[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vi c;
        for (int j = 0; j < all.size(); j++)
        {
            if (!check[all[j] + a[i]])
            {
                check[all[j] + a[i]] = true;
                c.pb(all[j] + a[i]);
            }
        }
        for(auto s : c) all.pb(s);
        if (check[a[i]])
            continue;
        check[a[i]] = true;
        all.pb(a[i]);
    }
    sort(all.begin(), all.end());
    cout << all.size() << endl;
    for (int j = 0; j < all.size(); j++)
        cout << all[j] << ' ';
} 