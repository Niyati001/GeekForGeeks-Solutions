class Solution {
  public:
    void solve(int open, int close, int n, string curr, vector<string>& ans){
        if(open==n/2 && close== n/2){
            ans.push_back(curr);
            return;
        }
        
        // add '('
        if(open<= n/2){
            solve(open+1, close, n, curr+ "(", ans);
        }
        
        // add')'
        if(close< open){
            solve(open, close+1, n, curr+ ")", ans);
        }
    }  
  
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        solve(0,0,n, "", ans);
        return ans;
    }
};