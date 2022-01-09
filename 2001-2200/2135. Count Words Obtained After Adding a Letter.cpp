// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/discuss/1676859/Trie-vs.-Hashset
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for (auto &w : startWords) {
            sort(begin(w), end(w));
            s.insert(w);
        }
        int res = 0;
        for (auto &w : targetWords) {
            sort(begin(w), end(w));
            for (int i = 0; i < w.size(); ++i) {
                if (s.count(w.substr(0, i) + w.substr(i + 1))) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};
