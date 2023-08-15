// https://leetcode.cn/problems/apply-operations-to-maximize-score/solutions/2385936/gong-xian-fa-dan-diao-zhan-pythonjavacgo-23c4/
// https://www.bilibili.com/video/BV1wh4y1Q7XW/?spm_id_from=333.1007.tianma.1-1-1.click&vd_source=48e4bed01dd155111c1b309b768743f6
const int MX = 1e5 + 1;
int omega[MX];
int init = []() {
    for (int i = 2; i < MX; i++)
        if (omega[i] == 0) // i 是质数
            for (int j = i; j < MX; j += i)
                omega[j]++; // i 是 j 的一个质因子
    return 0;
}();

class Solution {
    const long long MOD = 1e9 + 7;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }

public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1); // 质数分数 >= omega[nums[i]] 的左侧最近元素下标
        vector<int> right(n, n); // 质数分数 >  omega[nums[i]] 的右侧最近元素下标
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && omega[nums[st.top()]] < omega[nums[i]]) {
                right[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const int i, const int j) {
            return nums[i] > nums[j];
        });

        long long ans = 1;
        for (int i: id) {
            long long tot = (long long) (i - left[i]) * (right[i] - i);
            if (tot >= k) {
                ans = ans * pow(nums[i], k) % MOD;
                break;
            }
            ans = ans * pow(nums[i], tot) % MOD;
            k -= tot; // 更新剩余操作次数
        }
        return ans;
    }
};

