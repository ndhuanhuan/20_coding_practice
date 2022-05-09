// clearer version
class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        set.erase({scores[playerId], playerId});
        scores[playerId] += score;
        set.insert({scores[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0;
        int count = 0;
        // Traverse from big to small
        for (auto it = set.rbegin(); it != set.rend() && count < K; it++) {
            count++;
            sum += it->first;
        }
        return sum;
    }
    
    void reset(int playerId) {
        set.erase({scores[playerId], playerId});
        scores[playerId] = 0;
    }

private:
    unordered_map<int, int> scores;
    set<pair<int, int>> set;  // <score, player id>
};


class Leaderboard {
public:
    
    map<int,int> M;
    set<pair<int,int>> S;
      
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        S.erase({M[playerId],playerId});
        M[playerId] += score;
        S.insert({M[playerId],playerId});
    }
    
    int top(int K) {
        int res = 0;
        int c = 0;
        for(auto it = S.rbegin(); it!=S.rend() && c < K; it++) {
            res+=(it->first);
            c++;
        }
        return res;
    }
    
    void reset(int playerId) {
        S.erase({M[playerId],playerId});
        M[playerId] = 0;
    }
};
