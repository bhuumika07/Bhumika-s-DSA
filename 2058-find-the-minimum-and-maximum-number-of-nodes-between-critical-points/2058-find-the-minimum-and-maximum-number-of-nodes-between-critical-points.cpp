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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>indices;
        int count=0;
        ListNode* curr = head;
        int prev=-1;
        while( curr->next)
        {
            count++;
            int val = curr->val;
            int next = curr->next->val;
            if( prev == -1 )
            {
                prev=val;
                continue;
            }
            if( val > prev && val > next ) indices.push_back(count);
            if( val < prev && val < next ) indices.push_back( count);
            prev=val;
            curr=curr->next;
        }
        if(indices.size()==1) return {-1,-1};
        if(!indices.empty())
        {
            int size = indices.size();
            int maxi = indices[size-1] - indices[0];
            int mini = INT_MAX;
            for( int i=0; i<indices.size()-1;i++)
            {
                mini = min(mini , indices[i+1] - indices[i]);
            }
            
            return {mini,maxi};
        }
        return {-1,-1};
        
        
    }
};