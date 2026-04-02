/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int> &path, vector<vector<int>> &ans){
        if(!root) return;
        
        path.push_back(root-> data);
        
        if(!root-> left && !root-> right){
            ans.push_back(path);
        }
        else{
            solve(root-> left, path, ans);
            solve(root-> right, path, ans);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int> path;
        vector<vector<int>> ans;
        
        solve(root, path, ans);
        return ans;
    }
};