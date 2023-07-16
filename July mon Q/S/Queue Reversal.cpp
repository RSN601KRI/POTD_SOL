#include <queue>

class Solution {
public:
    queue<int> rev(queue<int> q) {
        std::queue<int> reversedQueue;
        
        // Reversing the queue using a temporary stack
        std::stack<int> tempStack;
        while (!q.empty()) {
            tempStack.push(q.front());
            q.pop();
        }
        
        while (!tempStack.empty()) {
            reversedQueue.push(tempStack.top());
            tempStack.pop();
        }
        
        return reversedQueue;
    }
};
