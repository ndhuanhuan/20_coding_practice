// https://leetcode.com/problems/count-good-triplets-in-an-array/discuss/1783185/Python-O(NlogN)-2-Solutions-using-Fenwick-Tree
// My c++ version
class FenwickTree {
    public:
        FenwickTree(int n): sums_(n+1, 0), N(n) {}
        void update(int i, int delta) {
            i += 1;
            while(i <= N) {
                sums_[i] += delta;
                i += lowbit(i);
            }
        }
    
        int query(int i) const {
            int sum = 0;
            i += 1;
            while(i != 0 ) {
                sum += sums_[i];
                i -= lowbit(i);
            }
            return sum;
        }
    
        int queryRange(int left, int right) {
            if(left > 0) {
                return query(right) - query(left-1);
            }
            return query(right);
        }
    private:
        static inline int lowbit(int x) {
            return x & (-x);
        }
        vector<int> sums_;
        int N;
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        //cout << "here00";
        
        FenwickTree fenwick1(n);
        FenwickTree fenwick2(n);

        for(int i = 0; i < n; ++i) {
            fenwick2.update(i, 1);
        }
        
        //cout << "here0";
        
        // reindex
        unordered_map<int, int> m; // number => index
        for(int i = 0; i < n; ++i) {
            m[nums1[i]] = i;
        }
        
        
        for(int i = 0; i < n; ++i) {
           nums2[i] = m[nums2[i]]; // finish reindex
        }
        
        //cout << "here";
        // finish reindex
        
        // count increasing triplets
        long long ans = 0;
        for(auto num: nums2) {
            if(num > 0 && num < n-1) {
                long long left_smaller = fenwick1.queryRange(0, num-1);
                long long right_larger = fenwick2.queryRange(num+1, n-1);
                ans += left_smaller * right_larger;
            }
            fenwick1.update(num, 1);
            fenwick2.update(num, -1);
        }
        
        return ans;
    }
};
