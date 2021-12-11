// Remove Duplicates from Sorted List

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if(temp == nullptr) return head;
        while(temp->next != nullptr){
            if(temp->val == temp->next->val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};