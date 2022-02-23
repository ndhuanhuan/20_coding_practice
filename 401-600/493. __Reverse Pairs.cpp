// https://leetcode.com/problems/reverse-pairs/discuss/162757/Python-BIT-using-ranks-Clear-O(nlog(n))
// My version
class FenwickTree {    
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { 
        return x & (-x); 
    }
    vector<int> sums_;
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<long> new_nums;
        for(auto num: nums) {
            new_nums.push_back(num);
        }
        
        for(auto num: nums) {
            new_nums.push_back((long)num * 2);
        }
        
        set<long> sorted_set(new_nums.begin(), new_nums.end());
        FenwickTree tree(sorted_set.size());
        int res = 0;
        unordered_map<long, int> ranks;
        int i = 0;
        for (auto itr = sorted_set.begin(); itr != sorted_set.end(); itr++, ++i) {
            ranks[*itr] = i + 1;
        }
        
        for(int j = nums.size() - 1; j >=0; --j) {
            res += tree.query(ranks[nums[j]] - 1);
            tree.update(ranks[(long)nums[j] * 2], 1);
        }
        return res;
    }
};
