/*
Good luck for those who are trying your best
May the most glorious victory come
File name: vnoj_c11str2.cpp
Code by : acident / lckintrovert
Created since : 07/08/2023 ~~ 15:31:50
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
 
string a, b;
void solve() {
    cin >> a >> b;
    string A = b + '$' + a;
    int m = b.size() + 1, n = A.size();
    vi z(n, 0);
    z[0] = -1;
    for(int i = 0, l = 0, r = 0; i < A.size(); i++) {
        
        if(i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && A[z[i]] == A[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 >= r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    int minLen = A.size() - 1;
    for(int i = n - 1; i >= m; i--) {
        if(z[i] + i == A.size() && A.size() - 1 - z[i] < minLen) {
            minLen = A.size() - z[i] - 1;
        }
    }
    minLen = a.size() + b.size() - minLen;
    for(int i = 0; i < a.size() - minLen; i++) cout << a[i];
    for(int i = 0; i < b.size(); i++) cout << b[i];
    // cout << minLen;abc
}      

signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}