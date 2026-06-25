class Solution {
public:

    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    static bool comp(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    }

    vector<int> jobSequencing(vector<int>& deadline,
                              vector<int>& profit) {

        int n = deadline.size();

        vector<pair<int,int>> jobs;
        int maxDeadline = 0;

        for(int i = 0; i < n; i++){
            jobs.push_back({deadline[i], profit[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), comp);

        parent.resize(maxDeadline + 1);

        for(int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int cnt = 0;
        int totalProfit = 0;

        for(auto job : jobs){

            int slot = find(job.first);

            if(slot > 0){

                cnt++;
                totalProfit += job.second;

                parent[slot] = find(slot - 1);
            }
        }

        return {cnt, totalProfit};
    }
};