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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next ) return NULL;
      
        int length = 0;
        ListNode* curr = head;
        while( curr ){
            length++;
            curr = curr->next;
        }
        int mid = length/2;
       
        length = 0;
        curr = head;
        while(curr){
            length++;
            if(length == mid){
                curr->next = curr->next->next;
                break;
            }
            curr=curr->next;
        }
       
        return head;
    }
};