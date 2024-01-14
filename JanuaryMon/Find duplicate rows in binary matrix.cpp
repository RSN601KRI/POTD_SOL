class node {
    public:
    vector<node*> next;
    
    node() {
        next = vector<node*> (2, nullptr);
    }
};

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        swap(N, M);
        
        node * root = new node();
        vector<int> ans;
        
        auto insert = [&](vector<int> &row) {
            node * cur = root;
            
            for(int i = 0; i < M; i++){
                if(cur -> next[row[i]] != nullptr){
                    cur = cur -> next[row[i]];
                }
                else{
                    node * newnode = new node();
                    cur -> next[row[i]] = newnode;
                    
                    cur = newnode;
                }
            }
        };
        
        auto find = [&](vector<int> &row) -> bool {
            node * cur = root;
            
            for(int i = 0; i < M; i++){
                if(cur -> next[row[i]] != nullptr){
                    cur = cur -> next[row[i]];
                }
                else{
                    return 0;
                }
            } 
            
            return 1;
        };
        
        for(int i = 0; i < N; i++){
            if(!find(matrix[i])){
                insert(matrix[i]);
            }
            else
                ans.push_back(i);
        }
        
        return ans;
    } 
};
