class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        const int n = parent.size();
        vector<vector<int>> g(n);
        
        int ans = 0;
        
        int root = -1;
        for(int i = 0; i < n; ++i) {
            if(parent[i] >= 0) {
                g[parent[i]].push_back(i);
            } else {
                root = i;
            }
            
        }
        
        
        int val = dfs(root, s, g, ans);
        ans=max(ans,val);
        return ans+1;
    }
    
    int dfs(int i,string& s, vector<vector<int>>& g, int& ans){
        vector<int> a;
        for(auto nbr:g[i]){
            if(s[nbr]!=s[i]) a.push_back(1+dfs(nbr,s, g, ans));
            else ans=max(ans,dfs(nbr,s, g, ans));
        }
        sort(a.begin(),a.end(),greater<int>());
        if(a.size()>=2) ans=max(ans,a[0]+a[1]);
        if(a.size()==0) return 0;
        return a[0];
    }
};
