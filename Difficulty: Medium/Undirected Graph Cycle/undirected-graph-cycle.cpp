class Solution {
  public:
    bool dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node]= true;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, node, vis, adj)== true) 
                    return true;
            }
            else if(adjNode!= parent) return true;
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &edge: edges){
            int u= edge[0];
            int v= edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis (V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)== true) return true;
            }
        }
        return false;
    }
};