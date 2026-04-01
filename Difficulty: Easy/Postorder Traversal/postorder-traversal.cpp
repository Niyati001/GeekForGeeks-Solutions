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
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        stack<Node*> st1, st2;
        st1.push(root);
        
        while(!st1.empty()){
            Node* node= st1.top();
            st1.pop();
            
            st2.push(node);
            
            if(node-> left) st1.push(node-> left);
            if(node-> right) st1.push(node-> right);
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top()-> data);
            st2.pop();
        }
        return ans;
    }
};