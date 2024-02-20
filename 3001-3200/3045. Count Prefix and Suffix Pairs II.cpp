// https://leetcode.cn/problems/count-prefix-and-suffix-pairs-ii/solutions/2644160/z-han-shu-zi-dian-shu-pythonjavacgo-by-e-5c2v/
// https://www.bilibili.com/video/BV1jZ42127Yf/?spm_id_from=333.1007.top_right_bar_window_dynamic.content.click&vd_source=48e4bed01dd155111c1b309b768743f6
struct Node {
    unordered_map<int, Node*> son;
    int cnt = 0;
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string> &words) {
        long long ans = 0;
        Node *root = new Node();
        for (string &s: words) {
            int n = s.length();
            auto cur = root;
            for (int i = 0; i < n; i++) {
                int p = (int) (s[i] - 'a') << 5 | (s[n - 1 - i] - 'a');
                if (cur->son[p] == nullptr) {
                    cur->son[p] = new Node();
                }
                cur = cur->son[p];
                ans += cur->cnt;
            }
            cur->cnt++;
        }
        return ans;
    }
};
