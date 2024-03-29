// https://leetcode.com/problems/sum-of-beauty-in-the-array/discuss/1472273/C%2B%2B-Left-and-Right
class Solution {
public:
    int sumOfBeauties(vector<int>& A) {
        int N = A.size(), left = A[0], ans = 0;
        vector<int> right(N, A[N - 1]);
        for (int i = N - 2; i > 0; --i) right[i] = min(right[i + 1], A[i]);
        for (int i = 1; i < N - 1; ++i) {
            if (A[i] > left && A[i] < right[i + 1]) ans += 2;
            else if (A[i] > A[i - 1] && A[i] < A[i + 1]) ans++;
            left = max(left, A[i]);
        }
        return ans;
    }
};
