/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev= NULL;
        Node* curr= head;
        
        while(curr!= NULL){
            Node* nextNode= curr-> next;
            
            curr-> next= prev;
            prev= curr;
            curr= nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        //  code here
        if(head== NULL || head-> next== NULL) return true;
        
        Node* slow= head;
        Node* fast= head;
        
        while(fast-> next!= NULL && fast-> next-> next!= NULL){
            slow= slow-> next;
            fast= fast-> next-> next;
        }
        
        Node* secondHalf= reverse(slow-> next);
        
        Node* first= head;
        Node* second= secondHalf;
        
        while(second!= NULL){
            if(first-> data!= second-> data)
                return false;
                
            first= first-> next;
            second= second-> next;
        }
        return true;
    }
};