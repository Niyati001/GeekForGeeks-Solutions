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
    int diameterVal= 0;
    
    int height(Node* root){
        if(root== NULL) return 0;
        
        int leftHeight= height(root-> left);
        int rightHeight= height(root-> right);
        diameterVal= max(diameterVal, leftHeight+ rightHeight);
        
        return (1+ max(leftHeight,rightHeight));
    }
    int diameter(Node* root) {
        height(root);
        return diameterVal;
    }
};