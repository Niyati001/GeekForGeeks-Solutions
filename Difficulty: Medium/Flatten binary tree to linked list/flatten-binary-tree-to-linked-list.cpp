class Solution {
  public:
    Node* prev= NULL;
    
    void solve(Node* root){
        if(root== NULL) return;
        
        solve(root-> right);
        solve(root-> left);
        
        root-> right= prev;
        root-> left= NULL;
        prev= root;
    }
    
    void flatten(Node *root) {
        solve(root);
    }
};