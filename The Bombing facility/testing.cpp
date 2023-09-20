/*
Good luck for those who are trying your best
May the most glorious victory come
File name: testing.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 11:34:47
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n;
string a[51], b[51];
void solve() {
    for(int i = 1; i <= 50; i++) {
        cin >> a[i];
    }
    string s; cin >> s;
    for(int i = 1; i <= 50; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= 50; i++) {
        cerr << a[i] << ' ' << b[i] << endl;
        if(a[i] != b[i]) {
            cout << "Sai test " << i << ": phải là " << a[i] << endl;
        }
    }
    cerr << s;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}