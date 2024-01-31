// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            struct TrieNode* node = root;
            for (char ch : key) {
                int index = ch - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->isLeaf = true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode* root, string key) {
        struct TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (!node->children[index]) {
                return false; // Character not found in the Trie
            }
            node = node->children[index];
        }
        return (node != nullptr && node->isLeaf);
    }
};