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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>collect;
        for( int i : nums) collect.insert(i);
        int count=0;
        int seq=0;
        ListNode* curr = head;
        while( curr )
        {
            if( collect.find(curr->val) != collect.end()) seq++;
            else { if( seq) count++; seq=0;}
            curr=curr->next;
        }
        if( seq) count++;
        return count;
        
    }
};