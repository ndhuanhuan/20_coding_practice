// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1655-distribute-repeating-integers/
// https://leetcode.com/problems/distribute-repeating-integers/discuss/935492/C%2B%2Bbacktrack-Backtrack-with-explanation
class Solution {
public:
    bool backtrack(vector<int> &n, const vector<int> &q, int k) {
        if (k == q.size())
            return true;  // All customers are satisfied
        for (int i = 0; i < n.size(); ++i) {
            if (n[i] >= q[k]) {
                n[i] -= q[k];  
                if (backtrack(n, q, k + 1)) {  // Trying to satisfy next customer
                    return true;
                }
                n[i] += q[k];
            }
        }
        
        return false;
    }
    
    bool canDistribute(vector<int>& n, vector<int>& q) {
        if (q.size() == 0) {
            return true;
        }
		// Calculate repeated nums
		vector<int> count(1001, 0);
        for (int i = 0; i < n.size(); ++i) {
            ++count[n[i]];
        }
        
		// Sort in reversed order
        sort(count.begin(), count.end(), greater<int>());
        sort(q.begin(), q.end(), greater<int>());
		
        // Max number of unique numbers we can use to satisfy each customer
        count.resize(q.size());
        
        return backtrack(count, q, 0);
    }
};
