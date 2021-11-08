// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/discuss/1563739/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& A) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2, sum = 0;
            for (int a : A)
                sum += (a + mid - 1) / mid;
            if (sum > n)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
