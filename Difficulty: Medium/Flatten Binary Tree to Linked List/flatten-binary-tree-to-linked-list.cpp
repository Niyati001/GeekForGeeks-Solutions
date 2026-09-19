/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* prev= NULL;
    
    void flatten(Node* root) {
        // code here
        if(root== NULL) return;
        
        flatten(root-> right);
        flatten(root-> left);
        
        root-> right= prev;
        root-> left= NULL;
        
        prev= root;
    }
};