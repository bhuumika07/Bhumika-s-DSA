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
    bool isPalindrome(ListNode* head) {
        // with the concept of slow and fast pointers --> my slow will be pointing to the half of the linkedlist
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode*rev = slow;
        ListNode*prev = NULL;
        ListNode* front = NULL;
        
        while(rev){
            front = rev->next;
            rev->next = prev;
            prev = rev;
            rev = front;
        }

        slow = head;
        while( slow && prev){
            if(slow->val != prev->val) return 0;
            slow = slow->next;
            prev = prev->next;
        }

        return 1;

    }
};