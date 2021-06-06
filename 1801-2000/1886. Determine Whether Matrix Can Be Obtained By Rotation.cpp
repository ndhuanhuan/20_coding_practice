class Solution {
public:
    vector<vector<int> > rotate(vector<vector<int> > & mat){
        vector<vector<int> > ret(mat);
        int n = mat.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                ret[j][n-1-i] = mat[i][j];
            }
        return ret;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++){
            mat = rotate(mat);
            if(mat==target) return true;
        }
        return false;
    }
};
