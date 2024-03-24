// https://leetcode.cn/problems/longest-common-suffix-queries/solutions/2704763/zi-dian-shu-wei-hu-zui-duan-chang-du-he-r3h3j/


struct Node {
    Node *son[26]{};
    int min_l = INT_MAX, i;
};

class Solution {
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery) {
        Node *root = new Node();
        for (int idx = 0; idx < wordsContainer.size(); ++idx) {
            auto &s = wordsContainer[idx];
            int l = s.length();
            auto cur = root;
            if (l < cur->min_l) {
                cur->min_l = l;
                cur->i = idx;
            }
            for (int i = s.length() - 1; i >= 0; i--) {
                int b = s[i] - 'a';
                if (cur->son[b] == nullptr) {
                    cur->son[b] = new Node();
                }
                cur = cur->son[b];
                if (l < cur->min_l) {
                    cur->min_l = l;
                    cur->i = idx;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (auto &s: wordsQuery) {
            auto cur = root;
            for (int i = s.length() - 1; i >= 0 && cur->son[s[i] - 'a']; i--) {
                cur = cur->son[s[i] - 'a'];
            }
            ans.push_back(cur->i);
        }
        return ans;
    }
};

