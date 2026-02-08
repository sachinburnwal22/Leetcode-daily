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
        ListNode* temp = head;
        ListNode* oddHead = new ListNode(-1);
        ListNode* eveHead = new ListNode(-1);

        ListNode* oddTail = oddHead;
        ListNode* eveTail = eveHead;
        int cnt = 1;
        while(temp != NULL){
            if(cnt%2 != 0){
                oddTail -> next = temp;
                oddTail = oddTail -> next;
            }else{
                eveTail -> next = temp;
                eveTail = eveTail -> next;
            }
            cnt++;
            temp = temp->next;
        }
        
        eveTail -> next = NULL;
        oddTail -> next = eveHead -> next;
        return oddHead -> next;
    }
};