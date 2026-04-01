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
  
    void helper(Node*root, vector<int> &vec){
        if(root== NULL) return;
        helper(root->left, vec);
        helper(root-> right, vec);
        vec.push_back(root-> data);
    }
    vector<int> postOrder(Node* root) {
        vector<int> vec;
        helper(root, vec);
        return vec;
    }
};