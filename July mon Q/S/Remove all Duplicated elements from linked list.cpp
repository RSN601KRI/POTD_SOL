/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node* dummy = new Node(0);
        dummy->next = head;
        
        Node* prev = dummy; // Pointer to the node before the current sequence of duplicates
        Node* curr = head;  // Pointer to the current node being examined
        
        while (curr) {
            // Move curr to the end of the current sequence of duplicates
            while (curr->next && curr->data == curr->next->data) {
                curr = curr->next;
            }
            
            // If prev->next is not curr, it means there was a sequence of duplicates
            if (prev->next != curr) {
                // Skip the entire sequence of duplicates
                prev->next = curr->next;
            } else {
                // Otherwise, move prev to curr
                prev = prev->next;
            }
            
            // Move curr to the next node
            curr = curr->next;
        }
        
        // The new head of the linked list is after the dummy node
        Node* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};