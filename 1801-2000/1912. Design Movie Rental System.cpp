// https://leetcode.com/problems/design-movie-rental-system/discuss/1298735/C%2B%2B-Vector%2BOrdered-Sets-Explained-Commented-Easy-to-Understand-Clean-code
class MovieRentingSystem {
public:
    vector<set<pair<int, int>>> unrented = vector<set<pair<int, int>>> (10010);
    vector<set<pair<int, int>>> getPrice = vector<set<pair<int, int>>> (10010);
    
    set<pair<int, pair<int, int>>> rented;
    
    MovieRentingSystem(int n, vector<vector<int>>& e){
        for(auto v: e){
            unrented[v[1]].insert({v[2], v[0]});            //unrented[movie].insert({price, shop})   --> each movie vector will be sorted by the price 
            getPrice[v[1]].insert({v[0], v[2]});            //checkPrice[movie].insert({shop, price}) --> each movie vector will be sorted by shop
        }
    }
    
    vector<int> search(int movie){
        vector<int> ans;
        int i=0;
        for(auto d: unrented[movie]){                               //get top 5 cheapest movies if present otherwise return all present in unrented list
            ans.push_back(d.second);
            i++;
            if(i>=5){
                break;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie){
        
        auto it = getPrice[movie].lower_bound({shop, INT_MIN});   // to know the price of the movie
        int price = (*it).second;
        
        unrented[movie].erase({price, shop});                       // remove the movie form unrented list
        
        rented.insert({price, {shop, movie}});                      // add movie to the rented set
    }
    
    void drop(int shop, int movie) {
        
        auto it = getPrice[movie].lower_bound({shop, INT_MIN});   // to know the price of the movie
        int price = (*it).second;
        
        unrented[movie].insert({price, shop});                      // add movie to the unrented set
        
        rented.erase({price, {shop, movie}});                       // remove the movie form rented list
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for(auto d: rented){                                         //get top 5 cheapest movies if present otherwise return all present in rented list
            ans.push_back({d.second.first, d.second.second});
            i++;
            if(i>=5){
                break;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
