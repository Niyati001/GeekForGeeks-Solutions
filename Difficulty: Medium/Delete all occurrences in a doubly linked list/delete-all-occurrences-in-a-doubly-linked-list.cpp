/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp= head;
        while(temp!= NULL){
            if(temp-> data== x){
                Node* nextNode= temp-> next;
                
                if(temp== head){
                    head= head-> next;
                    if(head!= NULL){
                        head-> prev= NULL;
                    }
                }
                else{
                    Node* prevNode= temp-> prev;
                    prevNode-> next= nextNode;
                    if(nextNode!= NULL)
                        nextNode-> prev= prevNode;
                }
                delete temp;
                temp= nextNode;
            }
            else{
                temp= temp-> next;
            }
        }
        return head;
    }
};