/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowptr = head;
        unordered_map<ListNode* , int> mpp;
        while(slowptr){
            if(mpp.find(slowptr) != mpp.end()) return slowptr;
            mpp[slowptr]++;
            slowptr = slowptr->next;
        }
        return NULL;
    }
};