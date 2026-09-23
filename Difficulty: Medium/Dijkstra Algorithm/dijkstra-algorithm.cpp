class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V, 1e9);
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            int wt= edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [dis, node]= pq.top();
            pq.pop();
            
            if(dis> dist[node])
                continue;
                
            for(auto it: adj[node]){
                int adjNode= it.first;
                int wt= it.second;
                
                if(dis+ wt< dist[adjNode]){
                    dist[adjNode]= dis+ wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};