/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* node){
        return node->left==NULL && node-> right==NULL;
    }
    
    void addLeftBoundary(Node* node, vector<int> &res){
        Node* curr= node-> left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr= curr->left;
            else curr= curr-> right;
            
        }
    }
    
    void addLeaves(Node* root, vector<int> &res){
        if(!root) return;
        
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        addLeaves(root-> left, res);
        addLeaves(root-> right, res);
    }
    
    void addRightBoundary(Node* node, vector<int> &res){
        Node* cur= node-> right;
        vector<int> temp;
        
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur= cur->right;
            else cur= cur->left;
        }
        
        for(int i= temp.size()-1; i>=0; i--){
            res.push_back(temp[i]);
        }    
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root) return res;
        
        if(!isLeaf(root)) res.push_back(root-> data);
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};