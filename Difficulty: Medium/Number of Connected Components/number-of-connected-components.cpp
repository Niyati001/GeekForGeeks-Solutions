class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node]= true;
        
        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited);
            }
            
        }
    }
  
    int countConnected(int V, vector<vector<int>>& edges) {
        // create adjacency list
        vector<vector<int>> adj(V);
        for(vector<int>& edge: edges){
            int u= edge[0];
            int v= edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // step 2: visited array
        vector<bool> visited(V, false);
        int components =0;
        
        // start dfs from univisited node
        for(int i=0; i< V; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                components++;
            }
        }
        return components;
    }
};