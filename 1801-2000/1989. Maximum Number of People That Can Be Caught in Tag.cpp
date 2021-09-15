// https://leetcode.com/problems/maximum-number-of-people-that-can-be-caught-in-tag/discuss/1439846/Greedy-Solutions
class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        queue<int> it, nit;
        int res = 0;
        for(int i = 0; i < team.size(); ++i) {
            if(team[i]) {
                it.push(i);
            } else {
                nit.push(i);
            }
            while (!it.empty() && it.front() < i - dist)
                it.pop();
            while (!nit.empty() && nit.front() < i - dist)
                nit.pop();
            if(!it.empty() && !nit.empty()) {
                it.pop();
                nit.pop();
                res +=1;
            }
        }
        
        return res;
    }
};
