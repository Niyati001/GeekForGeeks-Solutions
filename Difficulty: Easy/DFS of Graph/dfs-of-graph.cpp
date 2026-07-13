class Solution {
  public:
    void dfsHelp(int node, vector<vector<int>>& adj, int vis[], vector<int>& ans){
        vis[node]= 1;
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                dfsHelp(it, adj, vis, ans);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int V= adj.size();
        int vis[V]= {0};
        vector<int> ans;
        
        dfsHelp(0, adj, vis, ans);
        
        return ans;
    }
};