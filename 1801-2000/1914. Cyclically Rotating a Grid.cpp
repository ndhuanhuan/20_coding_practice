// https://leetcode.com/problems/cyclically-rotating-a-grid/discuss/1299560/C%2B%2B-oror-Easy-Solution-oror-brute-force-oror-4-pointer-approach
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {
        int n=g.size();
        int m=g[0].size();
        int t=0,l=0,r=m-1,b=n-1; 
		// t=top, l=left, r=right, b=bottom.
        while(t<b && l<r)
        {
            int tempk=k;
            int num=2*(r-l+b-t); // or num=(r-l+1)+(b-t)+(r-l)+(b-t-1); ie. counting the number of elements in current layer.
            tempk=k%num;
            while(tempk--) // rotating current layer tempk no. of times
            {
                int temp=g[t][l];
                for(int j=l;j<r;j++)
                    g[t][j]=g[t][j+1];
                int temp2=g[b][l];
                for(int i=b;i>t;i--)
                    g[i][l]=g[i-1][l];
                g[t+1][l]=temp;
                int temp3=g[b][r];
                for(int j=r;j>l;j--)
                    g[b][j]=g[b][j-1];
                g[b][l+1]=temp2;
                for(int i=t;i<b;i++)
                    g[i][r]=g[i+1][r];
                g[b-1][r]=temp3;
            }
            l++;
            r--;
            t++;
            b--;
        }
        
        return g;
    }
};
