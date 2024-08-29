/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if (head == NULL) return 0;

        // Step 1: Detect if there is a loop
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected
                break;
            }
        }

        // If no loop is detected
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }

        // Step 2: Find the starting point of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Calculate the length of the loop
        int loopLength = 0;
        Node *startOfLoop = slow;
        do {
            slow = slow->next;
            loopLength++;
        } while (slow != startOfLoop);

        return loopLength;
    }
};