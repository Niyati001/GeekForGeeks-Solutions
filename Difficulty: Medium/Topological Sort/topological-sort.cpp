class Solution {
public:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, vis, st, adj);
            }
        }

        // Push after visiting all neighbours
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Step 2: DFS
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Step 3: Pop stack to get topo order
        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};