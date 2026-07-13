/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        deque<Node*>dq;
        dq.push_back(root);
        root->next=NULL;
        while( !dq.empty() && root )
        {
            vector<Node*>level;
            int s =dq.size();
            for( int i=0; i<s; i++)
            {
                Node* node= dq.front();
                dq.pop_front();
                if(node->left) 
                {
                    level.push_back(node->left);
                    dq.push_back(node->left);
                }
                if( node->right)
                {
                    level.push_back( node->right);
                    dq.push_back( node->right);
                }
            }
            level.push_back(NULL);
            for( int i=0; i<level.size()-1; i++)
            {
                level[i]->next= level[i+1];
            }
        }

        return root;
        
    }
};