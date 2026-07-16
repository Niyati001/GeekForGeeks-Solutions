class Solution {
  public:
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node]= 1;
        
        for(auto it: adj[node]){
            if(!vis[it]) dfs1(it, adj, vis, st);
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<vector<int>>& revAdj, vector<int>& vis){
        vis[node]= 1;
        
        for(auto it: revAdj[node]){
            if(!vis[it]) dfs2(it, revAdj, vis);
        }
    }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            
            adj[u].push_back(v);
        }
        
        // step2:  topo order by finishing time
        vector<int>vis(V, 0);
        
        stack<int> st;
        for(int i=0; i<V;i++){
            if(!vis[i]) dfs1(i, adj, vis, st);
        }
        
        vector<vector<int>>revAdj(V);
        for(auto edge: edges)
            revAdj[edge[1]].push_back(edge[0]);
            
        // step4:  dfs on  reversed graph
        fill(vis.begin(), vis.end(), 0);
        
        int scc=0;
        
        while(!st.empty()){
            int node= st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs2(node, revAdj, vis);
            }
        }
        return scc;
    }
};