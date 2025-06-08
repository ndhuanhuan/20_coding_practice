// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/
// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/solutions/6821862/java-c-python-mono-deque-dp/
// Example explanation of 'All valid partitions ending at j can be formed by adding A[i..j] to partitions ending before i':

// Test case: [9,4,1,3,7]
// Curr element: 3 (index 3)
// [l,r] => [1,3]

// We have 3 options:
// dp[0] + sequence (4,1,3)
// dp[1] + sequence (1,3)
// dp[2] + sequence (3)

// Intuition being, i am sitting at 3. I can take either 3, (1,3), or (4,1,3). These are the sets for which max - min <= k at index 3.

// In other words, we need sum of dp[l-1] to dp[r-1].
// This can be achieved using prefix sum. Indices are adjusted by 1 to avoid handling negative index edge cases.

class Solution {
public:
    int countPartitions(vector<int>& A, int k) {
        int n = A.size(), mod = 1e9 + 7, acc = 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        deque<int> minq, maxq;
        for (int i = 0, j = 0; j < n; ++j) {
            while (!maxq.empty() && A[j] > A[maxq.back()])
                maxq.pop_back();
            maxq.push_back(j);
            while (!minq.empty() && A[j] < A[minq.back()])
                minq.pop_back();
            minq.push_back(j);
            while (A[maxq.front()] - A[minq.front()] > k) {
                acc = (acc - dp[i++] + mod) % mod;
                if (minq.front() < i)
                    minq.pop_front();
                if (maxq.front() < i)
                    maxq.pop_front();
            }

            dp[j + 1] = acc;
            acc = (acc + dp[j + 1]) % mod;
        }
        return dp[n];
    }
    
};
