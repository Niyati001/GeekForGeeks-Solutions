class Solution {
  public:
    void topo(int node, vector<int>& vis, vector<vector<pair<int, int>>>& adj, stack<int>& st){
        vis[node]=1;
        
        for(auto [v, w]: adj[node]){
            if(!vis[v])
                topo(v, vis, adj, st);
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto e: edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i])
               topo(i, vis, adj, st);
        }
        
        vector<int> dist(V, 1e9);
        
        dist[0]=0;
        
        while(!st.empty()){
            int node= st.top();
            st.pop();
            
            if(dist[node]!= 1e9){
                for(auto [v, w]: adj[node]){
                    if(dist[v]> dist[node]+ w){
                        dist[v]= dist[node]+ w;
                    }
                }
            }
        }
        for(auto &x: dist){
            if(x== 1e9){
                x=-1;
            }
        }
        return dist;
    }
};
