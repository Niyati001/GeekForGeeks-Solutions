class Solution {
  public:
    bool dfs(int v, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[v]= true;
        for(int neighbour: adj[v]){
            if(!visited[neighbour]){
                if(dfs(neighbour, v, adj, visited)){
                    return true;
                }
            }
            else if(neighbour!= parent) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // build adjacency list
        vector<vector<int>> adj(V);
        
        for(vector<int>& edge : edges){
            int u= edge[0];
            int v= edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // step2: visited array
        vector<bool> visited(V, false);
        
        //check every connected component
        for(int i=0; i<V; i++){
            if(!visited[i]) {
                if(dfs(i, -1, adj, visited)){
                    return true;
                }
            }
        }
     return false;   
    }
};