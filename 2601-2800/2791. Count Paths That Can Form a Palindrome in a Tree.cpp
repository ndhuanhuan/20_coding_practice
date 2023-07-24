// https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree/solution/yong-wei-yun-suan-chu-li-by-endlesscheng-n9ws/
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<pair<int,int> > > G(n);
        for(int i=1;i<n;i++){
            G[parent[i]].push_back({i,1<<(s[i]-'a')});
        }
        long long ans=0;
        unordered_map<int, int> cnt{{0,1}}; // One "empty path"
        std::function<void(int,int)> dfs  = [&](int now,int xor_val)  {
            for(auto &[to,x]:G[now]){
                int new_xor = xor_val^x;//异或和
                ans+=cnt[new_xor];
                for(int i=0;i<26;i++){
                    ans+=cnt[new_xor^(1<<i)];// x ^ (x^(1<<i)) = 1<<i
                }
                cnt[new_xor]++;
                dfs(to,new_xor);
            }
        };
        dfs(0,0);
        return ans;
    }
};
