class Solution {
public:
    long long incremovableSubarrayCount(vector<int> &a) {
        int n = a.size();
        int i = 0;
        while (i < n - 1 && a[i] < a[i + 1]) {
            i++;
        }
        if (i == n - 1) { // 每个非空子数组都可以移除
            return (long long) n * (n + 1) / 2;
        }

        long long ans = i + 2;
        for (int j = n - 1; j == n - 1 || a[j] < a[j + 1]; j--) {
            while (i >= 0 && a[i] >= a[j]) {
                i--;
            }
            ans += i + 2; // j已经固定， 左端点一共i+2种
        }
        return ans;
    }
};

