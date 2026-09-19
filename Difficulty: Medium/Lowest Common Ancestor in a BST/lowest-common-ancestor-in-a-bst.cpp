/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        if(root== NULL || root== n1 || root== n2) return root;
        
        Node* left= findLCA(root-> left, n1, n2);
        Node* right= findLCA(root-> right, n1, n2);
        
        if(left && right) return root;
        
        return left? left: right;
    }
};