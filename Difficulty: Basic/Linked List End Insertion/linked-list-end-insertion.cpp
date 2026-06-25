/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* newNode= new Node(x);
        
        if(head== NULL) return newNode;
        
        Node* temp= head;
        
        while(temp->next!= NULL){
            temp= temp-> next;
        }
        temp-> next= newNode;
        return head;
    }
};