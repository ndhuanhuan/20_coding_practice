// https://leetcode.com/problems/find-duplicate-file-in-system/discuss/104123/C%2B%2B-clean-solution-answers-to-follow-up
class Solution {
public:
    string sortSentence(string s) {
        istringstream iss(s);
        string word, ans;
        vector<string> v(9);
        while (iss >> word) {
            v[word.back() - '1'] = word.substr(0, word.size() - 1); // store the strings in a vector
        }
        for (int i = 0; i < 9 && v[i].size(); ++i) { // merge the strings in vector
            if (i > 0) ans += " ";
            ans += v[i];
        }
        return ans;
    }
};
