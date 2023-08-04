struct trieNode {
    trieNode* next[26];
    trieNode() {
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};
trieNode* rootNode = new trieNode();
void addString(string s) {
    trieNode* p = rootNode;
    for(int i = 0; i < s.size(); i++) {
        int temp = s[i] - 97;
        if(p -> next[temp] == nullptr) p -> next[temp] = new trieNode();
        p = p -> next[temp];
    }
}
string ans = "";

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs.size(); i++) {
            addString(strs[i]);
        }
        trieNode* p = rootNode;
        int cnt = 0, save = 0;
        for(int i = 0; i < 26; i++) {
            if(p -> next[i] == nullptr) {
            }
            else {
                cnt++;
                save = i;
            }

            if(i == 25 && (cnt == 0 || cnt >= 2)) return ans;
            else if(i == 25 && cnt == 1) {
                ans = ans + (char)(save + 97);
                p = p -> next[save];
                i = -1;
                cnt = 0;
            }
        }
        return ans;
    } 
};

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<string> lmao;
	int n; cin >> n;
	while(n--) {
		cin >> s;
		lmao.push_back(s);
	}
	string ret = Solution().longestCommonPrefix(lmao);
}