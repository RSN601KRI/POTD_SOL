/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
         if (head == NULL || x <= 0) {
            // If the list is empty or the position is invalid
            return head;
        }
        
        Node* current = head;

        // If the node to be deleted is the head node
        if (x == 1) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete current; // Free memory of the deleted node
            return head;
        }

        // Traverse the list to find the node to be deleted
        for (int i = 1; current != NULL && i < x; i++) {
            current = current->next;
        }

        // If the position is more than the number of nodes
        if (current == NULL) {
            return head;
        }

        // If the node to be deleted is not the last node
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }

        // If the node to be deleted is not the first node
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }

        // Free memory of the deleted node
        delete current;

        return head;
    }
};
