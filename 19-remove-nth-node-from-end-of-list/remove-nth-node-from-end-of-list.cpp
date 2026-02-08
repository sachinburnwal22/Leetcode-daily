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
    ListNode* reverse(ListNode* head){
        if(!head || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = reverse(head);
        
        ListNode* temp = newHead;
        if(n == 1){
            ListNode* del = newHead;
            newHead = newHead->next;
            delete del;
        }else{
            while(n > 2){
                temp = temp -> next;
                n--;
            }
            ListNode* toDel = temp -> next;
            temp -> next = temp->next->next;
            delete toDel;
        }
        return reverse(newHead);
    }
};