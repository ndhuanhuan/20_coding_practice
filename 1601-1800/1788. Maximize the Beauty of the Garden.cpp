// https://leetcode.com/problems/maximize-the-beauty-of-the-garden/discuss/1103676/Java-Prefix-sum-approach-with-a-slight-modification-O(N)-time-O(N)-space
class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map <int,int> mp;
        int res=INT_MIN;
        int sum=0;
        for(auto a:flowers){
            if(mp.find(a)!=mp.end()){
                res=max(res,sum+2*a-mp[a]);
            }
            if(a>0){
                sum=sum+a;
            }
            if(mp.find(a)==mp.end()){
                mp[a]=sum;
            }
             
        }
        return res;
    }
};
