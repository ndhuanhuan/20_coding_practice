// https://leetcode.com/problems/find-target-indices-after-sorting-array/discuss/1599800/C%2B%2B-O(N)-Time-Counting-Sort
class Solution {
public:
    vector<int> targetIndices(vector<int>& A, int target) {
        int cnt = 0, rank = 0; // `cnt` is the frequency of `target`, `rank` is the sum of frequencies of all numbers < target
        for (int n : A) {
            cnt += n == target;
            rank += n < target;
        }
        vector<int> ans;
        while (cnt--) ans.push_back(rank++);
        return ans;
    }
};
