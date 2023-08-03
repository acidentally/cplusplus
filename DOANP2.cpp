/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


/*
// //Only when want to open file
void FileOpen(string s) {
    freopen(s + ".in", "r", stdin);
    freopen(s + ".out", "w", stdout);
}
*/

int cinn() {
    int n; cin >> n;
    return n;
}

signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(0);
    int n, l, r; cin >> n;
    map<int, int> mapp;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        mapp[l] = max(mapp[l], r);
    }
    map<int, int>::iterator ptr = mapp.begin();
    l = ptr->fi; r = ptr->se;
    ptr++;
    int ans = 0;
    while(ptr != mapp.end()) {
        if(ptr -> fi <= r) {
            r = max(r, ptr -> se);
        }
        else {
            ans += r - l;
            l = ptr -> fi;
            r = ptr -> se;
        }
        ptr++;
    }
    
    cout << ans + r - l;
}