/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        return postorder_serialization(root);
    }
    
    string postorder_serialization(TreeNode* root) {
        
        if (root == nullptr)
            return "null";
        
        string left_serialize = postorder_serialization(root -> left);
        string right_serialize = postorder_serialization(root -> right);
        
        return to_string(root -> val) + "," + left_serialize + "," + right_serialize;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int l = data.length();
        queue<string> Queue;
        for (int i = 0; i < l; i++)
        {
            string s;
            while(i < l && data[i] != ',')
                s.push_back(data[i++]);
            
            
            Queue.push(s);
        }
        
        return deserialize(Queue);
    }
    
    TreeNode* deserialize(queue<string>& Queue) {
        
        if (Queue.empty())
            return nullptr;
        
        string peek = Queue.front(); Queue.pop();
        
        if (peek == "null")
            return nullptr;
        
        TreeNode* root = new TreeNode(stoi(peek));
        root -> left = deserialize(Queue);
        root -> right = deserialize(Queue);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));