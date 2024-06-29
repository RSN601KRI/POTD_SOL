/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
bool areIdentical(struct Node *head1, struct Node *head2) {
    // Traverse both lists
    while (head1 != NULL && head2 != NULL) {
        // If data of both nodes is not same
        if (head1->data != head2->data) {
            return false;
        }
        // Move to the next nodes
        head1 = head1->next;
        head2 = head2->next;
    }

    // Check if both lists are empty
    return (head1 == NULL && head2 == NULL);
}

// Helper function to print linked list
void printList(struct Node *node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Helper function to push a new node at the end of list
void appendNode(struct Node* &head, int new_data) {
    struct Node* new_node = new Node(new_data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
