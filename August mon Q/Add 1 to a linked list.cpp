/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        
        // Step 2: Add one to the reversed list
        Node* curr = head;
        Node* prev = NULL;
        int carry = 1; // We need to add one, so carry is initially set to 1
        while (curr != NULL && carry > 0) {
            int sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;
            prev = curr;
            curr = curr->next;
        }
        
        // If carry is still remaining, create a new node
        if (carry > 0) {
            prev->next = new Node(carry);
        }
        
        // Step 3: Reverse the list again to restore original order
        head = reverse(head);
        
        return head;
    }
};