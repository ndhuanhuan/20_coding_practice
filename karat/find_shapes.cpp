#include <iostream>
#include <string>
#include <vector>
#include <utility>

// there is an image filled with 0s and 1s. There is at most 
// one rectangle in this image filled with 0s, find the rectangle. Output 
// could be the coordinates of top-left and bottom-right elements of the rectangle, 
// or top-left element, width and height.


using namespace std;

void dfs(vector<vector<int>>& board,vector<pair<int,int>>& lst,int i,int j){
    if(i <0 || j <0 || i>=board.size() || j>=board[0].size() || board[i][j] == 1){
        return;
    }
    lst.push_back({i,j});
    board[i][j] = 1;
    dfs(board,lst,i+1,j);
    dfs(board,lst,i-1,j);
    dfs(board,lst,i,j+1);
    dfs(board,lst,i,j-1);

}

vector<vector<pair<int,int>>> find_shapes(vector<vector<int>> board){
    vector<vector<pair<int,int>>> res;
    for (size_t i = 0; i < board.size(); i++)
    {
       for(size_t j = 0;j<board[0].size(); j++){
           if(board[i][j] == 0){
               vector<pair<int,int>> lst;
                dfs(board,lst,i,j);
                res.push_back(lst);
           }

       }
    }
    
    return res;
}

int main(){
    // 0 0 0
    // 1 1 1
    // 0 0 1

    // 0 0 0
    // 1 1 1
    // 1 0 0
    vector<vector<int> > board = {{0,0,0},{1,1,1},{1,0,0}};
    auto res = find_shapes(board);
    for(int i = 0;i<res.size();i++){
        cout<<"next\n";
        for(int j = 0; j< res[i].size(); j++){
                cout<<"res:"<<res[i][j].first << ","<<res[i][j].second<<endl;
        }

    }


    return 0;
}
