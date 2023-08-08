/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1857B.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 11:22:59
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
string n;
void solve() {
    cin >> n;
    n = 'A' + n;   
    for(int i = 1; i < n.size(); i++) {
        if(n[i] >= '5') {
            for(int j = i; j < n.size(); j++) n[j] = '0';
            i--;
            n[i]++;
            while(n[i] >= '5' && i >= 0) {
                n[i] = '0';
                i--;
                if(i >= 0) n[i]++;
            }
            if(n[0] != 'A') n[0] = (char)'1';
            break;
        }
    }
    // cout << n;
    for(int i = 0; i < n.size(); i++) {
        if(n[i] == 'A') continue;
        cout << n[i];
    }
    cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}