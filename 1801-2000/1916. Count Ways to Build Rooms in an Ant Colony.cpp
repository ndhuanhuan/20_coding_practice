// https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/discuss/1299661/DFS-oror-Combinatorics-oror-Modulo-Inverse-oror-DP-oror-Solution-Explained-oror-Easy-Code-oror-Hard-Logic
class Solution {
    int mod =1e9+7;
    int dfs(int cur,vector<int>&sz,vector<int> adj[]){
        
        int ans = 0 ;
        for(auto next : adj[cur]) ans += dfs(next,sz,adj);
        return sz[cur] = ans + 1;
        
        
    }
    long power(long a, long expo){
        if(expo == 0 ) return 1;
        auto halfExpo = power(a , expo/2);
        auto fullExpo = halfExpo * halfExpo % mod;
        if(expo % 2) fullExpo = fullExpo * a % mod;
        return fullExpo;
        
    }
    long modInverse(long productSz) {
        return power(productSz , mod-2);
    }
public:
    int waysToBuildRooms(vector<int>& a) {
        int n = a.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++) adj[a[i]].push_back(i);
        vector<int> sz(n,0);
        dfs(0,sz,adj);
        
        long nFact = 1;
        for(int i = 2;i<=n;i++ ) nFact = nFact * i % mod;
        long productofSz = 1;
        for(int i=0;i<n;i++) productofSz = productofSz * sz[i] % mod;
        long inverseOfDenominator = modInverse(productofSz);
        return nFact * inverseOfDenominator % mod;
    }
};
