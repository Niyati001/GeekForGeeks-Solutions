class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            int wt= edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src]=0;
        
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis= pq.top().first;
            int node= pq.top().second;
            
            pq.pop();
            for(auto it: adj[node]){
                int neigh= it.first;
                int wt= it.second;
                
                if(dist[neigh]> dis+ wt){
                    dist[neigh]= dis+ wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist;
    }
};