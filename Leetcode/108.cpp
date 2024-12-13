/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 108.cpp
Code by : acident / lckintrovert
Created since : 01/12/2024 ~~ 16:35:42
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        1e5 + 10;
const int INF       =        1e18;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> TreeNodeToArray(TreeNode* root) {
    vector<int> ans;

    if(root == nullptr) {
        ans.pb(-1);
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        if(q.front() == nullptr) {
            ans.pb(-1);
        }
        else {
            TreeNode* cur = q.front();
            ans.pb(cur -> val);

            if(cur -> left != nullptr) q.push(cur -> left);
            else q.push(nullptr);
            if(cur -> right != nullptr) q.push(cur -> right);
            else q.push(nullptr);
        }
        
        q.pop();
    }

    return ans;
}
class Solution {
public:

    bool left = 0, right = 1;

    void func(vector<int>& nums, TreeNode* sub_root, int l, int r, bool dir) {
        if(l > r) return;

        int mid = (l + r) >> 1;
        
        TreeNode *cur_node = new TreeNode();
        cur_node -> val = nums[mid];

        if(dir == left) sub_root -> left = cur_node;
        else sub_root -> right = cur_node;
        
        func(nums, cur_node, l, mid - 1, left); 
        func(nums, cur_node, mid + 1, r, right); 

        return;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // [0, ... nums.size() - 1]
        int divide = nums.size() / 2;
        TreeNode holder = TreeNode(nums[divide]);
        TreeNode *root = &holder;

        func(nums, root, 0, divide - 1, left);
        func(nums, root, divide + 1, nums.size() - 1, right); 

        return root;
    }
} test;


inline void solve() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = test.sortedArrayToBST(a);

    vector<int> ans = TreeNodeToArray(root);
    for(auto s : ans) cout << s << ' ';
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/