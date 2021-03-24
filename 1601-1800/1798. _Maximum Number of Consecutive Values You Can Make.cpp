// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/discuss/1118766/C%2B%2BJavaPython-with-picture
class Solution {
public:
  int getMaximumConsecutive(vector<int>& c) {
        sort(begin(c), end(c));
        int max_val = 1;
        for (auto i = 0; i < c.size() && c[i] <= max_val; ++i)
            max_val += c[i];
        return max_val;
    } 
};
