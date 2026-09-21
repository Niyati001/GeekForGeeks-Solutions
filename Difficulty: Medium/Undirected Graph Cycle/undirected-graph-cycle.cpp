class Solution {
  public:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node]=1;
        
        for(auto neig: adj[node]){
            if(!vis[neig]){
                if(dfs(neig, node, vis, adj))
                    return true;
            }
            else if(neig!= parent)
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int>vis(V, 0);
        
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};