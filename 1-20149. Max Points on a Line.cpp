class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> count;
            int same_points = 1;
            int max_points = 0;
            auto& p1 = points[i];
            for (int j = i + 1; j < n; ++j) {
                auto& p2 = points[j];
                
                if (p1[0] == p2[0] && p1[1] == p2[1]) 
                    same_points++;
                else
                    max_points = max(max_points, ++count[getSlope(p1, p2)]);
            }
            ans = max(ans, max_points + same_points);
        }
        
        
        return ans;
    }
    
    
    
private:
    // slope dy/dx
    pair<int, int> getSlope(vector<int>& p1, vector<int>& p2) {
        const int dx = p2[0] - p1[0];
        const int dy = p2[1] - p1[1];
        
        // horizontal line
        if (dy == 0) return { p1[1], 0 };
        
        // vertical line
        if (dx == 0) return { 0, p1[0] };
        
        const int d = gcd(dx, dy);
        
        return { dy / d, dx / d };
    }
    
    int gcd(int a, int b) {
        int temp;
        while(b != 0) {
            temp = a % b;
            a = b;
            b = temp;
        }
        
        return a;
    }
};
