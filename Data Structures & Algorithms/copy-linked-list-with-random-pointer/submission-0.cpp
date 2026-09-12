/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* mover = dummy;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            Node* nx = temp->next;
            temp->next = newNode;
            newNode->next = nx;
            temp = nx;
        }
        temp = head;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        // mover->next = temp->next;
        while(temp){
            Node* nx = temp->next;
            mover->next = nx;
            mover = mover->next;
            temp->next = nx->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
