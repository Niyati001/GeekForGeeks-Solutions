/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    Node* markParents(Node* root, unordered_map<Node*, Node*>& parent, int target){
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode= NULL; 
        
        while(!q.empty()){
            Node* node= q.front();
            q.pop();
            
            if(node-> data== target)
                targetNode= node;
            
            if(node->left){
                parent[node-> left]= node;
                q.push(node-> left);
            }
            
            if(node-> right){
                parent[node-> right]= node;
                q.push(node-> right);
            }
        }
        return targetNode;

    }
    
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode= markParents(root, parent, target);
        
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(targetNode);
        visited[targetNode]= true;
        
        int time=0;
        
        while(!q.empty()){
            int size= q.size();
            bool burned= false;
            
            for(int i=0; i< size; i++){
                Node* node= q.front();
                q.pop();
                
                
                if(node-> left && !visited[node-> left]){
                    visited[node-> left]= true;
                    q.push(node-> left);
                    burned= true;
                }
                
                if(node-> right && !visited[node-> right]){
                    visited[node-> right]= true;
                    q.push(node-> right);
                    burned= true;
                }
                
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]]= true;
                    q.push(parent[node]);
                    burned= true;
                }
            }
            if(burned) time++;
        }
        return time;
    }
};