#include <iostream>
#include <string>
#include <vector>
#include <utility>

// there is an image filled with 0s and 1s. There is at most 
// one rectangle in this image filled with 0s, find the rectangle. Output 
// could be the coordinates of top-left and bottom-right elements of the rectangle, 
// or top-left element, width and height.


using namespace std;

vector<std::pair<int,int>> findTriangle(vector<vector<int>> rectangle){
    vector<std::pair<int,int>> res;

    for(int i = 0;i<rectangle.size();i++){
        for(int j = 0; j<rectangle[i].size();j++){

            if(rectangle[i][j] == 0){
                res.push_back(make_pair(i,j));
                int height = 1;
                int width = 1;

                while(height + i <rectangle.size() && rectangle[i+height][j]==0){
                    height++;

                }
                while(width + j <rectangle[0].size() && rectangle[i][j + width]==0){   
                    width++;

                }

                for(int m = i;m<i+height;m++){
                    for(int n = j;n<j+width;n++){
                        rectangle[m][n] = 1;
                }
               res.push_back(make_pair(i+height - 1,j+width - 1));
            }
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
    vector<vector<int> > rectangle = {{0,0,0},{1,1,1},{1,0,0}};
    auto res2 = findTriangle(rectangle);
    for(int i = 0;i<res2.size();i+=2){
         cout<<"res:"<<res2[i].first << ","<<res2[i].second<<" => "<<res2[i+1].first<<","<<res2[i+1].second<<endl;
    }


    return 0;
}
