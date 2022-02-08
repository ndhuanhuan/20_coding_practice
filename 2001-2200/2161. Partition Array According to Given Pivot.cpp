// https://leetcode.com/problems/partition-array-according-to-given-pivot/discuss/1746999/C%2B%2B-Two-Pointers-O(N)-time
class Solution {
public:
    vector<int> pivotArray(vector<int>& A, int pivot) {
        vector<int> gt; // numbers greater than pivot
        int j = 0, cnt = 0; // `j` is the write pointer. `cnt` is the count of numbers equal to pivot
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] < pivot) A[j++] = A[i];
            else if (A[i] == pivot) ++cnt;
            else gt.push_back(A[i]);
        }
        while (cnt--) A[j++] = pivot;
        for (int i = 0; i < gt.size(); ++i) A[j++] = gt[i];
        return A;
    }
};
