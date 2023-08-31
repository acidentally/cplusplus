/*
Good luck for those who are trying your best
May the most glorious victory come
File name: thptchuyenntucoder_2102E.cpp
Code by : acident / lckintrovert
Created since : 28/08/2023 ~~ 16:14:46
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
char s[maxn] = {}, x;
int cntA[maxn] = {}, cntB[maxn] = {};  
void solve() {
    int idx = 1;
    while(cin >> x) {
        s[idx++] = x;
    }
    idx--;
    for(int i = 1; i <= idx; i++) {
        cntA[i] = cntA[i - 1];
        cntB[i] = cntB[i - 1];
        if(s[i] == 'A') cntA[i]++;
        else cntB[i]++;
    }

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

AB 
BA 
AA
/*A place to scribble thoughts

*/