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
        if( root ==NULL)
        {
            return "N,";
        }
        string ans="";
        ans+=to_string(root->val) +",";
        ans+=serialize(root->left);
        ans+=serialize(root->right);

        return ans;     
    }
    TreeNode* helper( vector<string>&nodes, int& index)
    {
        if( nodes[index]=="N")
        {
            index++;
            return NULL;
        }
        TreeNode* root = new TreeNode( stoi(nodes[index]));
        index++;
        root->left=helper(nodes,index);
        root->right=helper(nodes,index);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp="";
        for( char ch : data )
        {
            if( ch ==',')
            {
                nodes.push_back(temp);
                temp="";
            }
            else
            {
                temp+=ch;
            }
        }
        int index=0;
        return  helper( nodes,index);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));