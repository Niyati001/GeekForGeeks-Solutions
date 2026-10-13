class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<int> adj[26], indegree(26, 0);
        vector<bool> exists(26, false);
        
        for(string word: words){
            for(char c: word){
                exists[c- 'a']= true;
            }
        }
        
        for(int i=0; i<words.size()-1; i++){
            string a= words[i], b= words[i+1];
            int j=0;
            
            while(j< a.size() && j<b.size() && a[j]== b[j]){
                j++;
            }
            
            if(j< min(a.size(), b.size())){
                int u= a[j]-'a';
                int v= b[j]- 'a';
                adj[u].push_back(v);
                indegree[v]++;
            }
            
            else if(a.size()> b.size()){
                return "";
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<26; i++)
            if(exists[i] && indegree[i]==0)
                q.push(i);
                
        string order= "";
        
        while(!q.empty()){
            int u= q.front();
            q.pop();
            order+= char(u+ 'a');
            
            for(int v: adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        int total=0;
        
        for(int i=0; i<26; i++){
            if(exists[i])
                total++;
        }
        
        if(order.size()!= total)
            return "";
            
        return order;
        
    }
};