
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;  
    for(int i = 0; i<nums1.size();i++)
    {
        for(int j= 0; j<nums2.size();j++)
        {
            if(q.size()>=k && nums1[i]+nums2[j]>q.top().first+q.top().second) break;
            if(q.size()>=k && nums1[i]+nums2[j]<=q.top().first+q.top().second){
                q.push({nums1[i],nums2[j]});
                q.pop();
            }
            else if (q.size()<k) q.push({nums1[i],nums2[j]});  
        }
    }
    while(!q.empty())
    {
        vector<int> tmp = {q.top().first, q.top().second};
        q.pop(); ans.push_back(tmp);
    }
    return ans;
    }
    
    struct cmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.first + a.second < b.first + b.second;
        }
    };
};


//http://www.cnblogs.com/grandyang/p/5653127.html
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
		priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
		for(int i=0 ; i<min((int)nums1.size(),k); ++i )
		{
			for(int j=0;j < min((int)nums2.size(),k);++j)
			{
				if(q.size()<k)
				{
					q.push({nums1[i],nums2[j]});
				}
				else if (nums1[i] + nums2[j] < q.top().first + q.top().second) 
				{
                    q.push({nums1[i], nums2[j]}); q.pop();
				}
			}
		}
		while(!q.empty())
		{
			res.push_back(q.top());
			q.pop();
		}
		return res;
    }
	
	struct cmp
	{
		bool operator() (pair<int,int> &a, pair<int,int> &b)
		{
			return a.first+a.second<b.first+b.second;
		}
	};
};
