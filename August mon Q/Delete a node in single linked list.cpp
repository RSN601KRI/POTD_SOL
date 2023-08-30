#include <bits/stdc++.h>

/* Link list Node 
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

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    function<void(Node *, Node *)> traverse = [&](Node * cur, Node * prev) {
        --x;
        
        if(x == 0){
            if(prev == nullptr){
                head = cur -> next;
            }
            else{
                prev -> next = cur -> next;
            }
            
            delete(cur);
            
            return;
        }
        
        traverse(cur -> next, cur);
    };
    
    traverse(head, nullptr);
    
    return head;
}