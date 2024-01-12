class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // Create a stack to store the first k elements.
        stack<int> s;

        // Enqueue the first k elements into the stack.
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Enqueue the reversed elements back into the queue.
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Enqueue the remaining elements back into the queue.
        for (int i = 0; i < q.size() - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
