/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>store;
        for( int i=0; i<lists.size();i++)
        {
            ListNode*curr=lists[i];
            while(curr)
            {
                store.push_back(curr->val);
                curr=curr->next;
            }
        }
        if(store.size()==0) return {};
        sort( store.begin(), store.end());
        ListNode* head=new ListNode(store[0]);
        ListNode* curr=head;
        for( int i=1; i<store.size();i++)
        {
            ListNode* temp=new ListNode(store[i]);
            curr->next=temp;
            curr=curr->next;
        }
        return head;
        
    }
};