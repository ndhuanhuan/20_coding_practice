// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/807526/C%2B%2B-Solution-Explained-First-and-Last-Element
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector <int> ans;
        int size = rounds.size();
        
        if(rounds[0] <= rounds[size-1]) {
            for(int i=rounds[0]; i<= rounds[size-1]; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        else {
            for(int i=1; i<= rounds[size-1]; i++) {
                ans.push_back(i);
            }   
            
            for(int i=rounds[0]; i<=n; i++) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
