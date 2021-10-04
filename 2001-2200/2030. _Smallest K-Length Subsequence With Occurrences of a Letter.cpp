// https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/discuss/1500365/Concise-C%2B%2B-O(N)-Stack-Solution
// https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/discuss/1500174/PythonJava-O(N)-greedy-solution-using-a-stack
class Solution {
public:
    string smallestSubsequence(string s, int k, char target, int reps) {
        int N = s.length(), remain = count(s.begin(), s.end(), target);
        string stack;

        for (int i = 0; i < N; i++) {
            while (!stack.empty() && stack.back() > s[i] && (N - i + stack.length() > k) && (stack.back() != target || remain > reps)) {
                if (stack.back() == target)
                    reps++;
                stack.pop_back();
            }

            if (stack.length() < k) {
                if (s[i] == target || k - (int)stack.length() > reps) {
                    stack += s[i];
                    if (s[i] == target)
                        reps--;
                }
            }

            if (s[i] == target)
                remain--;
        }
        return stack;
    }
};
