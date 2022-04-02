class Solution {
public:
    int triangularSum(vector<int>& A) {
        for (int i = A.size(); i >= 1; --i) {
            for (int j = 0; j < i - 1; ++j) {
                A[j] = (A[j] + A[j + 1]) % 10;
            }
        }
        return A[0];
    }
};
