class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt=0;
        int n=target.size();
        unordered_map<string, int> map;
        for(auto num : nums)
            map[num]++;
        
        for(int i=0; i<target.size(); i++){
            string s1=target.substr(0,i);
            string s2=target.substr(i,n);
            if(s1 == s2){
               cnt+=map[s1]*(map[s2]-1);
            }else{
                cnt+=map[s1]*map[s2]; 
            }
        }
        return cnt;
    }
};
