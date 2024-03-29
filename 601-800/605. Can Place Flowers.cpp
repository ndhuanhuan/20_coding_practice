class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size() && n > 0; i++){
            if(flowerbed[i]==0 &&(i==0 || flowerbed[i-1]==0) &&(i ==flowerbed.size()-1 || flowerbed[i+1]==0) ){
                n--;
                i++;
            } 
        }
        return n == 0? true:false;
    }
};


//http://www.cnblogs.com/grandyang/p/6983982.html
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (n == 0) return true;
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};
