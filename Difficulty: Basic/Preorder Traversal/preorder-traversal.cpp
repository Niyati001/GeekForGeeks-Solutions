/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
        void helper(Node* root, vector<int> &vec){
        if(root== NULL) return;
        
        vec.push_back(root-> data);
        helper(root-> left, vec);
        helper(root->right, vec);
        }
        
        vector<int> preOrder(Node* root) {
            vector<int> vec;
            helper(root, vec);
            return vec;
        }
};
