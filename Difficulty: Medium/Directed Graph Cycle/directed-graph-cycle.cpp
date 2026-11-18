class Solution {
  public:
    bool dfs(int node, vector<int>& pathVis, vector<int>& vis, vector<vector<int>>& adj){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto neig: adj[node]){
            if(!vis[neig]){
                if(dfs(neig, pathVis, vis, adj))
                    return true;
            }
            else if(pathVis[neig])
                return true;
        }
        pathVis[node]= 0;
        
        return false;
    }
    bool isCyclic(vector<vector<int>>& adj){
        // code here
        int V= adj.size();
        vector<int> pathVis(V, 0);
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, pathVis, vis, adj))
                    return true;
            }
        }
        return false;
    }
};