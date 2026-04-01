/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        if(root== NULL) return {};
        
        vector<int> vec;
        vector<int> leftTree= inOrder(root->left);
        
        vec.push_back(root-> data);
        
        vector<int> rightTree= inOrder(root-> right);
        
        vec.insert(vec.begin(), leftTree.begin(), leftTree.end());
        vec.insert(vec.end(), rightTree.begin(), rightTree.end());
        
        return vec;
    }
};