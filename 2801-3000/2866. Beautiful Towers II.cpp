class Solution {
public:
    long long maximumSumOfHeights(vector<int> &a) {
        int n = a.size();
        vector<long long> suf(n + 1);
        stack<int> st;
        st.push(n); // 哨兵
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            while (st.size() > 1 && x <= a[st.top()]) {
                int j = st.top();
                st.pop();
                sum -= (long long) a[j] * (st.top() - j); // 撤销之前加到 sum 中的
            }
            sum += (long long) x * (st.top() - i); // 从 i 到 st.top()-1 都是 x
            suf[i] = sum;
            st.push(i);
        }

        long long ans = sum;
        st = stack<int>();
        st.push(-1); // 哨兵
        long long pre = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            while (st.size() > 1 && x <= a[st.top()]) {
                int j = st.top();
                st.pop();
                pre -= (long long) a[j] * (j - st.top()); // 撤销之前加到 pre 中的
            }
            pre += (long long) x * (i - st.top()); // 从 st.top()+1 到 i 都是 x
            ans = max(ans, pre + suf[i] - a[i]);
            st.push(i);
        }
        return ans;
    }
};

