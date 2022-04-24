class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int i, prev;
        map <int, int> count;
        vector <int> v(persons.size(), 0);
        for(i=0; i<flowers.size(); i++){
            count[flowers[i][0]]++;
            count[flowers[i][1]+1]--;
        }
        for(i=0, prev=0; i<persons.size(); i++)
            count[persons[i]]+=0;
        
        for(auto it=count.begin(); it!=count.end(); it++){
            if(it==count.begin())
                prev=it->second;
            else{
                count[it->first]+=prev;
                prev=count[it->first];
            }
        }
        for(i=0; i<persons.size(); i++)
            v[i]=count[persons[i]];
        return v;
    }
};
