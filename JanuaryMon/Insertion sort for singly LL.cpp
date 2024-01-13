/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/


class Solution {
public:
    Node* insertionSort(struct Node* head_ref) {
        // If the list is empty or has only one node, it is already sorted
        if (head_ref == NULL || head_ref->next == NULL) {
            return head_ref;
        }

        Node *sortedList = NULL; // Initialize sorted linked list

        // Traverse the given linked list
        while (head_ref != NULL) {
            Node *current = head_ref;
            head_ref = head_ref->next;

            // If the current node needs to be inserted at the beginning
            if (sortedList == NULL || current->data < sortedList->data) {
                current->next = sortedList;
                sortedList = current;
            } else {
                // Locate the node before the point of insertion
                Node *temp = sortedList;
                while (temp->next != NULL && temp->next->data < current->data) {
                    temp = temp->next;
                }

                // Insert the current node
                current->next = temp->next;
                temp->next = current;
            }
        }

        return sortedList;
    }
};
