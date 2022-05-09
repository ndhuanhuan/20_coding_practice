// classic sweep line
// sort from x from small to large
// 
// for "Entering" we need to process higher/taller one first
// for "leaving" we need to process lower one first For example, -1, -5, -10. Last processed one is -10. And after removing abs(-10)
// there is still a valid height, then it is another building's entering line, which should be added to answer (AKA second tallest one in huahua's video)

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int, int> Event;
        // x, h
        
        vector<Event> es;
        hs_.clear();
        
        for (const auto& b : buildings) {
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }
        
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2) {
            if(e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });
        
        vector<vector<int>> res;
        
        for(const auto& e: es) {
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);
            
            if (entering) {
                if (h > this->maxHeight()) {
                    res.push_back({x, h});
                }
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if(h > this->maxHeight()) {
                    res.push_back({x, this->maxHeight()});
                }
            }
            
        }
        
        
        return res;
    }

private:
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }
    
    multiset<int> hs_;
};
