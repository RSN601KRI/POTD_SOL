class Solution {
  public:
    vector<Node*> printAllDups(Node* root) {
        // Code here
        vector<Node*> result;
        unordered_map<string, pair<int, Node*>> subtreeMap;
        serializeTree(root, subtreeMap, result);
        return result;
    }

private:
    string serializeTree(Node* node, unordered_map<string, pair<int, Node*>>& subtreeMap, vector<Node*>& result) {
        if (!node) return "#";
        
        string leftSerial = serializeTree(node->left, subtreeMap, result);
        string rightSerial = serializeTree(node->right, subtreeMap, result);
        string serial = to_string(node->data) + "," + leftSerial + "," + rightSerial;
        
        if (subtreeMap[serial].first == 1) {
            result.push_back(node);
        }
        subtreeMap[serial] = {subtreeMap[serial].first + 1, node};
        
        return serial;
    }
};
