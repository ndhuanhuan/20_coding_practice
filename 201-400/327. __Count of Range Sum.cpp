// https://leetcode.com/problems/count-of-range-sum/discuss/1236813/C%2B%2B-clean-code-or-O(NlogN)-or-BIT
class Solution {
    vector<int> fenwick;
    void add(int i, int val) { for(; i < fenwick.size(); i += i&-i)      fenwick[i] += val; }
    void sum(int i, int &o)  { for(; i;                  i -= i&-i) o += fenwick[i];        }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        fenwick.resize(n+1);
        
        vector<long> prefix = {nums[0]};
        for(int i = 1; i < n; i++) prefix.push_back( prefix[i-1] + nums[i] );
        
        vector<pair<long,int>> sorted;
        for(int i=0;i<n;i++)sorted.push_back({prefix[i],i+1});
        sort(sorted.begin(),sorted.end(),[](auto&x,auto&y){return x.first<y.first;});

        int L = 0, U = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            long prefix = sorted[i].first; if(prefix>=lower&&prefix<=upper) count++;
            long hi = prefix - lower;
            long lo = prefix - upper;
            while( U < n && sorted[U].first <= hi ) add( sorted[U++].second,  1 ); // add every prefix <= hi, can include invalid ones which will be removed by next while loop
            while( L < n && sorted[L].first <  lo ) add( sorted[L++].second, -1 ); // remove those prefix  < lo, since they are invalid
            sum( sorted[i].second-1, count ); // only sum those index smaller than current index, previous 2 while loop may include those indexes larger than current index, so they are ignored.
        }
        return count;
    }
};
