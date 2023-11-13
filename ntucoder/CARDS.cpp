/*
Good luck for those who are trying your best
May the most glorious victory come
File name: CARDS.cpp
Code by : acident / lckintrovert
Created since : 25/08/2023 ~~ 19:34:14
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, u;
char x;
priority_queue<int> qu;
void solve() {
    cin >> n;
    while(n--) {
        cin >> x;
        if(x == 'A') {
            cin >> u;
            qu.push(u);
            continue;
        }
        else {
            if(qu.empty()) {cout << -1 << endl; continue;}
            int d = qu.top(), c = 0;
            while(!qu.empty() && qu.top() == d) qu.pop();
            cout << d << ' ' << c << endl;
        }
    }
    if(qu.empty()) {
        cout << -1;
        return;
    }
    while(!qu.empty()) {
        cout << qu.top() << ' ';
        qu.pop();   
    }
} 
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/