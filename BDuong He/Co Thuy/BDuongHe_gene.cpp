/*
Good luck for those who are trying your best
May the most glorious victory come
File name: BDuongHe_gene.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 09:02:47
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e3 + 10;
int const INF       =       1e18;
 
int n;
char a[maxn], b[maxn] = {};
vector<pi> cnt;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i] == a[i]) {
            if(l != i) cnt.push_back({l, i - 1});
            l = i + 1;
        }
    }
    if(l != n + 1) cnt.push_back({l, n});
    
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}