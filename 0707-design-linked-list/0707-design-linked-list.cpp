
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
    };
    ListNode* head = NULL;
    MyLinkedList() {
        // head = NULL;
    }
    
    int get(int index) {
        index++;
        if(!head) return -1;
        ListNode* curr = head ;
        int count = 0;
        while( curr){
            count++;
            if( index == count) return curr->val;
            curr = curr->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode * temp = new  ListNode(val);
        temp->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        ListNode* curr = head;
        ListNode* temp = new  ListNode(val);
        if(!head) {head = temp ; return ;}
        while(curr->next) curr = curr->next;
        curr->next = temp;
    }
    
    void addAtIndex(int index, int val) {
        index++;
        int count = 0;
        ListNode* temp = new ListNode(val);
        if( index == 1) {
            temp->next = head;
            head = temp;
            return;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            count++;
            if( count == index - 1){
                ListNode* next = curr->next;
                curr->next = temp;
                temp->next = next;
            }
            curr = curr->next;
        }

        
    }
    
    void deleteAtIndex(int index) {
        index++;
        if(!head) return;
        if( index == 1){
            head = head->next;
            return;
        }
        int count = 0;
        ListNode* curr = head;
        while(curr){
            count++;
            if( count == index-1){
                if(curr->next)
                curr->next = curr->next->next;
                return;
            }
            curr=curr->next;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */