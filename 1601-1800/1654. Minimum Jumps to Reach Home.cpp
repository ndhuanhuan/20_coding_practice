// https://zxi.mytechroad.com/blog/searching/leetcode-1654-minimum-jumps-to-reach-home/
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        constexpr int maxK = 4000;
        if(x == 0) return 0;
        queue<pair<int, bool>> q{{{0, true}}};
        unordered_set<int> seen1, seen2;
        for(auto f: forbidden) {
            seen1.insert(f);
            seen2.insert(f);
        }
        seen1.insert(0);
        int step = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [cur, forward] = q.front(); q.pop();
                if(cur == x) return step;
                if(cur > maxK) continue;
                if(seen1.insert(cur + a).second) {
                    q.emplace(cur + a, true);
                }
                
                if(cur - b >= 0 && forward && seen2.insert(cur-b).second) {
                    q.emplace(cur - b, false);
                }
            }
            ++step;
        }
        
        return -1;
    }
};
