/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if (head == NULL) {
            return -1; // Return -1 if the linked list is empty
        }

        Node* slow = head; // Slow pointer moves one step at a time
        Node* fast = head; // Fast pointer moves two steps at a time

        // Traverse the list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;        // Move slow pointer by one node
            fast = fast->next->next;  // Move fast pointer by two nodes
        }

        // Slow pointer will be at the middle when the loop ends
        return slow->data;
    }
};