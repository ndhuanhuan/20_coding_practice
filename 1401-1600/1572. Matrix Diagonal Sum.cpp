class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        if(mat.size()==1)
            return mat[0][0];
        int i=0,j=0,sum=0;
        while(i<mat.size() && j<mat[i].size())
        {
            sum+=mat[i][j];
            i++;
            j++;
        }
        i=0;
        j=mat[i].size()-1;
        while(i<mat.size() && j>=0)
        {
            sum+=mat[i][j];
            i++;
            j--;
        }
        if(mat.size()%2==0)
            return sum;
        return sum-mat[mat.size()/2][mat.size()/2];
    }
};
