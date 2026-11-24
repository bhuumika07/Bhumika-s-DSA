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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // n++;
        if(!head) return NULL;
        int count = 0;
        ListNode* curr = head;
        while( curr ){
            count++;
            curr = curr->next;
        }
        int doit = count - n;
        if(doit == 0 ){
            head = head->next;
            return head;
        }
        count = 0;
        curr = head;
        while( curr ){
            count++;
            if(count == doit){
                if( curr->next ) curr->next = curr->next->next;
                break;
            }
            curr= curr->next;
        }
        return head;

    }
};