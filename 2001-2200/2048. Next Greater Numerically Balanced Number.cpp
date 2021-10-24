// https://leetcode.com/problems/next-greater-numerically-balanced-number/discuss/1537631/next_permutation
class Solution {
public:
    int base[13] = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};
    int nextBeautifulNumber(int n) {
        string s = to_string(n);
        int res = 1224444;
        for (int nn : base) {
            string ss = to_string(nn);
            if(ss.size() < s.size()) continue;
            if (ss.size() > s.size()) {
                res = min(res, nn);
            } else {
                do {
                    if (ss > s) {
                        res = min(res, stoi(ss));
                    }
                } while(next_permutation(begin(ss), end(ss)));
            }
                
        }
        return res;
    }
    
    

};
