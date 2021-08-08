// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1390319/How-to-reach-the-optimal-solution-or-Explained-with-Intuition-and-Diagram
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int mismatch = 0;
        for (int i = 0; i < s.length (); i++) {
            char ch = s[i];
            if (ch == '[')
                st.push(ch);
            else {
                if (!st.empty())
                    st.pop();
                else 
                    mismatch++;
            }
        }
        return (mismatch + 1) / 2;
    }
};
