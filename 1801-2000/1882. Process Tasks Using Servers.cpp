// https://leetcode.com/problems/process-tasks-using-servers/discuss/1239958/C%2B%2B-accepted-solution-with-detailed-comment-(two-priority-queues)
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		//store servers in a min pq with pair<weight, server_idx) in s
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> s;
        for (int i = 0; i<servers.size(); i++){
            s.push({servers[i], i});
        }
		//store (endTime, server_weight used, server_idx used) in min pq endTime
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long,3>>> endTime;
        long long time = 0;
		//output res
        vector<int> res;
        int i = 0; //keep track task idx
        while (i < tasks.size()){
            //retrieve completed servers
            while(!endTime.empty() && endTime.top()[0] <= time){
                auto [e, server1, server_idx] = endTime.top(); endTime.pop();
                s.push({server1, server_idx});
            }
			//execute new task 
            while(i < tasks.size() && i <= time){
                int cur_start = tasks[i];
				// When we have available servers
                if (!s.empty()){
                    auto [cur_server, server_idx] = s.top(); s.pop();
                    i++;
                    res.push_back(server_idx);
                    endTime.push({time+cur_start, cur_server, server_idx});
                }
				// no server available
                else{
                    time = max(time, endTime.top()[0]-1); //speed up simulation
                    break;
                }
            }
            time += 1;
        }
        return res;
    }
};
