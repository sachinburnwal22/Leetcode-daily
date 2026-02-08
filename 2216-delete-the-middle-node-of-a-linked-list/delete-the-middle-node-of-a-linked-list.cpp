class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: empty or single node
        if(!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
