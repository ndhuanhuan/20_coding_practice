class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        long long m = mass;
        for (int i=0;i<n;i++) {
            if (asteroids[i] <= m)
                m +=asteroids[i];
            else
                return false;
        }
        return true;
    }
};
