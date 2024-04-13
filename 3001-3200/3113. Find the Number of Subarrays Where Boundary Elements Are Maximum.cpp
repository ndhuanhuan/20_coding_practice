// https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/solutions/5017056/java-c-python-stack-o-n/
class Solution {
public:
    long long numberOfSubarrays(vector<int>& A) {
        vector<vector<int>> stack;
        long long res = 0;
        for (int& a : A) {
            while (!stack.empty() && stack.back()[0] < a)
                stack.pop_back();
            if (stack.empty() || stack.back()[0] != a)
                stack.push_back({a, 0});
            res += ++stack.back()[1];
        }
        return res;
    }
};
