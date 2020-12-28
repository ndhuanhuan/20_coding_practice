// https://zxi.mytechroad.com/blog/trie/leetcode-1707-maximum-xor-with-an-element-from-array/
class Trie {
public:
  Trie(): children{nullptr, nullptr} {}  
  Trie* children[2];
};
class Solution {
public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    const int n = nums.size();
    sort(begin(nums), end(nums));    
    
    const int Q = queries.size();
    for (int i = 0; i < Q; ++i)
      queries[i].push_back(i);
    sort(begin(queries), end(queries), [](const auto& q1, const auto& q2) {
      return q1[1] < q2[1];
    });
    
    Trie root;    
    auto insert = [&](int num) {
      Trie* node = &root; 
      for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!node->children[bit])
          node->children[bit] = new Trie();
        node = node->children[bit];
      }
    };
        
    auto query = [&](int num) {
      Trie* node = &root;
      int sum = 0;
      for (int i = 31; i >= 0; --i) {
        if (!node) return -1;
        int bit = (num >> i) & 1;
        if (node->children[1 - bit]) {
          sum |= (1 << i);
          node = node->children[1 - bit];
        } else {
          node = node->children[bit];
        }
      }
      return sum;
    };
    
    vector<int> ans(Q);
    int i = 0;
    for (const auto& q : queries) {
      while (i < n && nums[i] <= q[1]) insert(nums[i++]);
      ans[q[2]] = query(q[0]);
    }  
    return ans;
  }
};
