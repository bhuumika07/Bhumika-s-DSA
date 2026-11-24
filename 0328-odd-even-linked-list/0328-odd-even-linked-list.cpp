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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* oddptr = odd;
        ListNode* evenptr = even;
        ListNode* curr = head;
        int count = 0;
        while( curr ){
            count++;
            ListNode* temp = curr;
            curr=curr->next;
            temp->next = NULL;
            if( count % 2 == 0){
                evenptr->next = temp;
                evenptr = evenptr->next;
            }
            else{
                oddptr->next = temp;
                oddptr = oddptr->next;
            }
          
        }

        oddptr = odd->next;
        evenptr = even->next;
        curr = oddptr;
        while(curr->next){
            curr=curr->next;
        }
        curr->next = evenptr;
        return oddptr;
    }
};