// https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/discuss/1459111/Visualization-with-code-or-C%2B%2B
// https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/discuss/1458486/Python-Strict-O(n)-Solution
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        const int n = parents.size();
        vector<int> res(n, 1);
        vector<int> seen(100010, 0);
        
        auto it = find(nums.begin(), nums.end(), 1);
        if(it == nums.end()) {
            return res;
        }
        
        unordered_map<int, vector<int>> children;
        
        // vector<vector<int>> children(n , vector<int>(n));
        for(int i = 1; i < n; ++i) {
            if(children.find(parents[i]) == children.end()) {
                children[parents[i]] = vector<int>();
            }
            children[parents[i]].push_back(i);
        } 
        
        int node_index = it - nums.begin(), miss = 1;
        while(node_index != -1) {
            dfs(node_index, seen, children, nums);
            while(seen[miss] == 1) {
                ++miss;
            }
            res[node_index] = miss;
            node_index = parents[node_index];
        }
        
        return res;
    }
    
    void dfs(int node_index, vector<int>& seen, unordered_map<int, vector<int>>& children, vector<int>& nums) {
        if(seen[nums[node_index]]) return;
        for(int i: children[node_index]) {
            dfs(i, seen, children, nums);    
        }
        
        seen[nums[node_index]] = 1;
    }
};
