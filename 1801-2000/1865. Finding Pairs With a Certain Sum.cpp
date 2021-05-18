// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/discuss/1211203/Two-Sum-Hashmap
class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        swap(n1, nums1);
        swap(n2, nums2);
        sort(begin(n1), end(n1));
        for (auto n : n2)
            ++m[n];
    }
    void add(int index, int val) {
        --m[n2[index]];
        n2[index] += val;
        ++m[n2[index]];
    }
    int count(int tot) {
        int res = 0;
        for (auto i = 0; i < n1.size() && n1[i] < tot; ++i) {
            auto it = m.find(tot - n1[i]);
            if (it != end(m))
                res += it->second;
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
