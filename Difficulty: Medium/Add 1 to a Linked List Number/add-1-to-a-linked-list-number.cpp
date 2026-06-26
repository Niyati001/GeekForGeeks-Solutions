/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
          Node* prev= NULL;
          Node* curr= head;
          
          while(curr){
              Node* nextNode= curr-> next;
              curr-> next= prev;
              prev= curr;
              curr= nextNode;
          }
          return prev;
    }
    
    Node* addOne(Node* head) {
       head= reverse(head);
       Node* temp= head;
       
       int carry=1;
       
       while( temp && carry){
           int sum= temp-> data + carry;
           temp-> data= sum% 10;
           carry= sum/10;
           
           if(carry && temp-> next== NULL){
               temp-> next= new Node(0);
           }
           temp= temp-> next;
       }
       return reverse(head);
    }
};